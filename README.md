# messy-endtoend-ml
First shot at implementing machine learning from scratch. This means writing everything from the data loading to implementing whichever algorithm(s) I choose. 

This project also serves as a way to really get comfortable using git as that seems long overdo.

Start date: 09/23/19
# Structure
.hpp's contain declarations and defintions, main uses them to work with data/. Possible goal is to recreate some of tensorflow's overloaded general function calls such as fit and predict.

# Tenative plans
Load data from csv [x]

Add command-line functionality [x]
  
     Implement flags [ ]

Implement data partitioning (train/test split) [x]

     Split by columns (seperate features and target) [x]
  
     Split by rows (seperate train and test) [x]
  
Write template or abstract to be used for defining models with virtual functions like fit and predict [ ]

    Possibly implement a way to save the state of a model to be loaded later [ ]

Implement statistic model(s) [ ]

Implement geometric model(s) [ ]

Implement neural model(s) [ ]

Integrate with visualization library to present results [ ]
