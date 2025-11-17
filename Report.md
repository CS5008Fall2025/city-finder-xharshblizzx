# Report
Fill out these report questions.


1. What is the difference between a directed and undirected graph?

A directed graph has edges that go in one direction, like a one-way street. An undirected graph has edges that go both ways, like a two-way road.

2. What is the Big O of Dijkstra's algorithm....
   * Assuming you used an array (or list) to store the vertices.
   * Assuming you used a heap / priority queue to store the vertices.

With an array: O(V^2), because for each vertex, you scan all vertices to find the minimum distance.
With a heap: O((V+E) log V), which is better for graphs with many edges.

3. Explain in your own words what that means for larger graphs when trying to find the shortest distance.

For big graphs, using an array makes it slow because you check every vertex each time, which takes a lot of time. With a heap, it's faster as it quickly finds the next closest vertex, so it handles large maps better.

## Deeper Thinking
4. For this assignment, you didn't need the most "efficient" set of data structures (for example, a heap wasn't required). However, think on the scale of google/apple maps - they have to deal with millions of vertices and edges. What data structures would you use to store the graph? Why? Somethings to consider - would you be able to store the entire graph at a time? Could you break it up into smaller pieces? How would you do that? Would there be advantages to caching/memoization of paths? You are free to explore your thoughts on this subject/reflect on various ideas. Other than a realization of some scalability of problems, there isn't a wrong answer.

For google maps, I'd use a database like a graph database to store the graph, not all in memory. Break it into regions or tiles, load only nearby areas. Caching common paths helps speed up repeated queries, like popular routes.

## Future Understanding
5. Related to shortest distance, is a problem called the "messenger" or "traveling sales person" problem commonly abbreviated to TSP. This problem is to find the shortest path that visits **every** vertex in a graph. Another way to look at it, is you are an delivery driver, and you have a series of packages to deliver. Can you find an optimal path for your deliveries that minimizes the total distance traveled? Imagine if you had 5 stops. How many different paths are there?  There are 120 possible paths to look at! (assuming fully connected routes).
   * How many possible paths are there if you have 6 stops?
   * How many possible paths are there if you have 10 stops?

For 6 stops: 120 paths.
For 10 stops: 362880 paths.

6. What type of growth is this problem?

Exponential growth, factorial.

7. Take some time to research TSP problems. It falls under a certain classification of problems? What is it?

NP-complete.

8. Provide some examples of fields / problems that use TSP.

Delivery routes, circuit board drilling, DNA sequencing.

> [!TIP]
> We are having you explore TSP, so you can see the terms used for problem classification that are often the foundation of computer science theory. You will not be asked to know about TSP outside of this assignment or even problem classification. Computer Science is often about dealing with problems considered "too hard" or "impossible", and finding ways to make them possible! As such, knowing topics such as N, NP, NP-Complete, etc. is important to understand the limits (to break).


## Technical Interview Practice Questions
For both these questions, are you are free to use what you did as the last section on the team activities/answered as a group, or you can use a different question.

1. Select one technical interview question (this module or previous) from the [technical interview list](https://github.com/CS5008-khoury/Resources/blob/main/TechInterviewQuestions.md) below and answer it in a few sentences. You can use any resource you like to answer the question.

What is the difference between TCP and UDP? TCP is reliable, connection-oriented, ensures data arrives in order. UDP is fast, connectionless, no guarantees.

2. Select one coding question (this module or previous) from the [coding practice repository](https://github.com/CS5008-khoury/Resources/blob/main/LeetCodePractice.md) and include a c file with that code with your submission. Make sure to add comments on what you learned, and if you compared your solution with others.
