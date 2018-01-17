Hopefully the code is pretty easy to follow.
I did not create a class for prim's algorithm because I did not see a reason to.
Instead, you can find it in main.cpp. The function itself returns a plain graph object, 
but by my design of prim's algo, the returned graph will be a tree (MWST/MST).

My output is first the weight of a 10 node test graph that I created with an expected weight of 21.
The second section of output is in relation to a randomly generated 100 node graph. You should see 
first, the resulting MST from running Prim's algo on it (represented as an adjacency-list graph object), 
then you should see the total weight of the MST. In my testing, the values for the total weight are usually
between 100 and 150.