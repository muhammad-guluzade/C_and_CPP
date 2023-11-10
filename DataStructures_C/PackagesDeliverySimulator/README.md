# Indexing earthquakes
## How it works?
The program implements **priority queue** data structure in order to simulate the work of the post office with a particular number of employees and packages to be delivered.

The program reads inputs from the **command line**. They have to be in the following format : (number of packages, the number of delivery employees, the maximum arrival time, and the maximum
service time)

*Maximum arrival time - The time that the **latest** package will arrive to the post office*

*Maximum service time - The maximum time that will be required to **deliver** a package*

During its runtime, the program imitates the workflow of the post office. There are **four types** of packages: red (highest priority), orange (lower than red), yellow (lower than orange), and green (lowest priority). Once an employee is assigned a package, they are busy and cannot deliver the next package. As soon as the employee becomes free, they take the package that arrived earliest and that has the highest priority. It means that if the green package arrived before red, the employee will still take the red one. In the end, the program will display the report of job done.

### Report
================Report================
=The number of Delivery Employees: 2
=The number of Packages: 5
=Number of Packages for each Package Label:
=Red: 1
=Orange: 1
=Yellow: 2
= Green: 1
=Number of packages for each Delivery Employee:
=Delivery Employee 1 delivered: 4
=Delivery Employee 2 delivered: 1
=Completion time: 23
=Average time spent in the queue: 1.8
=Maximum waiting time: 5

 You can see the sample report above.
