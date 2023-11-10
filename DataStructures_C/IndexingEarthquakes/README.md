# Indexing earthquakes
## How it works?
The program implements AVL tree data structure in order to store the earthquakes according to names of the places. Somewhat similar to [EarthquakeDataAnalysis](https://github.com/muhammad-guluzade/C_and_CPP/tree/main/DataStructures_C/EarthquakesDataAnalysis) program, but with a few key differences.

The program reads earth.txt file given as a command line argument and stores each earthquake's details in a separate tree node. In case there is a place with multiple earthquakes, the tree node is going to point to a linked list which stores the details of each earthquake that occured at a particular place. During the process of storing the earthquakes, the tree balances itself.

In the end, the program leaves the user with AVL tree data structure which contains some of the tree nodes as linked lists. The structure of the tree is such that when doing pre-order traversal, the program displays the places in alphabetical order. The user has three options to perform.
- Option 1
  - Display all earthquakes.
- Option 2
  - Display the earthquakes of the most dangerous place. (The place with the longest linked list).
- Option 3
  - Display the weakest earthquake. The program traverses the entire tree along with each node of each linked list in order to find the smallest magnitude.

### Structure of earth.txt file
| Place     | Magnitude | Latitude  | Longitude  | Tsunami |
|-----------|-----------|-----------|------------|---------|
| Country2  | 4.9       | -42.2914  | 173.8065   | 1       |

Tsunami column represents whether there was a tsunami during the earthquake (1) or wasn't (0).
