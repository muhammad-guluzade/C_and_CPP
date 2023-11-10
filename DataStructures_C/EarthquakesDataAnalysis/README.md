# Earthquakes analyzer
## Main point of the program
The main point of the program is to practice linked lists implementation in C.
## How it works?
The program starts by reading earth.txt file of certain structure. Then, the linked list data structure is implemented in order to store each of the earthquakes. Each node of this linked list has the potential to start another linked list. This is needed in case there are two earthquakes in the same place (place with the same name in earth.txt file).

After successfully storing the details of earthquakes inside a nested linked list, some options are offered to the user to analyze or modify the data.
- Option 1
  - Remove all earthquakes that have magnitude below certain threshold (for example, if the user wants to delete all earthquakes that have the magnitude below 3.0, they need to choose option 1, and enter a threshold of 3)
- Option 2
  - 

  ### Structure of earth.txt file
  | Place      | Year | Month | Day | Magnitude | Latitude | Longitude | Tsunami |
  |------------|------|-------|-----|-----------|----------|-----------|---------|
  | Location 1 | 2023 | 01    | 01  | 7.2       | 34.567   | -120.789  | 1       |

  Tsunami column represents whether there was a tsunami (1) or wasn't (0).

