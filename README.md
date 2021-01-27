# CS 561: Data Systems Architecture - TemplateZonemaps


## About

TemplateZonemaps is a simple template for you, the student, to use for the simple
implementation project in CS 561. Note that this is a high level template, it is
not extensive, rather it is meant to help guide you on what we expect when
you implement the zonemaps. You can use this as base code or start from
scratch. You may require additional helper functions to satisfy the requirements of the project.

## Generating Workloads
You will be asked to generate workloads of a specific size, with varying noise levels. A workload generator
is provided as part of the API that performs the required functionality. Compile the workload generator using 
the "make" command, and execute using
```c
./workloadgenerator <domain_size> <noise_percentage> <windowThreshold>
```

## Zone Map Header
The zonemaps.h header file is a template that defines the basic components of a zone map data structure. It is 
required to implement the data structure using this template in a separate file named "zonemaps.cpp". You are 
free to modify certain components of the template to improve performance of the data structure, however the core 
functionality should remain the same. In your implementation, it is important to comment your code to highlight various 
design decisions and logic. 

## Testing 
The main.cpp file provides a foundational testing framework expected for this project. You are required to generate the 
workloads, read the data and build the zone map, perform point queries and range queries. For point queries, use the simple 
query generator function inside the main.cpp file. Refer to the assignment instruction document for range queries. Both point 
queries and range queries are to be timed for evaluating performance. The execution times are to be written in a log file along with 
other relevant details about the workload, such as: domain size, noise percentage, window threshold, etc. 

## Contact

If you have any questions please feel free to see Aneesh in office hours, or
email your queries at aneeshr@bu.edu.
