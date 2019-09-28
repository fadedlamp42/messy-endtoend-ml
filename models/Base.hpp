#ifndef MODEL_BASE_H
#define MODEL_BASE_H
#include <iostream>
#include "../core/Table.hpp"

class BaseModel{
    virtual void iterate(Table features, Table targets){
        cout << "Iterate called" << endl;
    }

    public:
    void fit(Table features, Table targets, int epochs = 10, int batch_size = 1){
        cout << "Fit called" << endl;
    }

    virtual Table predict(Table features){
        cout << "Predict called" << endl;
        Table result;
        return result;
    }
};
#endif
