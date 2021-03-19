import re, os
from os import listdir
from os.path import isfile, join

import matplotlib.pyplot as plt
import numpy as numpy
import imageio

# The path to the graph data
GRAPH_DATA_PATH = "bubble_sort.graph"

# The color map to use for the scatter plot
GRAPH_CMAP = "gist_rainbow"

# The output file name for the gif
GIF_OUTPUT_NAME = "bubble-sort.gif"

# The number of seconds between each frame in the gif.
GIF_FRAME_DURATION = 1

def tryint(s):
    try:
        return int(s)
    except:
        return s

def alphanum_key(s):
    return [ tryint(c) for c in re.split("([0-9]+)", s) ]

def main():
    # Prompt the user to clear the frames directory
    if(input("Would you like to clear existing frames? (Y/n)") == "Y"):
        filelist = [ f for f in os.listdir("frames") if f.endswith(".png") ]
        for f in filelist:
            os.remove(os.path.join("frames", f))

    # Prompt the user to generate frames
    if(input("Would you like to generate frames? (Y/n)") == "Y"):
        with open(GRAPH_DATA_PATH, "r") as file:
            lines = file.readlines()
            print("Generating {0} Frames!".format(len(lines)))

            frame_counter = 1
            for line in lines:
                string_data = line.split(" ")[:-1]
                num_data = [int(x) for x in string_data]
                x_axis = [num_data.index(x) for x in num_data]

                plt.scatter(x_axis, num_data, marker=".", c=num_data, s=100, cmap=GRAPH_CMAP)
                plt.savefig("frames/frame-{0}.png".format(frame_counter))
                plt.clf()

                frame_counter += 1        

    # Create GIF from frames
    files = [f for f in listdir("frames/") if isfile(join("frames/", f))]
    if len(files) > 0:
        files.sort(key=alphanum_key)

        kargs = { 'duration': GIF_FRAME_DURATION }
        with imageio.get_writer(GIF_OUTPUT_NAME, mode="I", **kargs) as writer:
            
            print("Stiching together the GIF!")
            for file in files:
                image = imageio.imread("frames/" + file)
                writer.append_data(image)

    else:
        print("You need to generate frames to create a GIF!")

if __name__ == "__main__":
    main()