#include "SegmentTree.h"


int main(){

    vector<int> v1={-1,2,5,0};

    SegmentTree* datos[]={new ST_sum(v1.size()),new ST_max(v1.size()),new ST_min(v1.size())}; 
    cout<<"------------------------------------------------"<<endl;
    cout<<"Segment Tree SUMA :"<<endl;
    datos[0]->build(v1,0,v1.size()-1,1);
    cout<<"------------------------------------------------"<<endl;
    datos[0]->print();    
    cout<<"------------------------------------------------"<<endl;
    int suma=datos[0]->query(0,v1.size()-1,0,1,1);
    cout<<"Resultado : "<<suma<<endl;

    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"Segment Tree MAX :"<<endl;
    datos[1]->build(v1,0,v1.size()-1,1);
    cout<<"------------------------------------------------"<<endl;
    datos[1]->print();    
    cout<<"------------------------------------------------"<<endl;
    int max=datos[1]->query(0,v1.size()-1,0,1,1);
    cout<<"Resultado : "<<max<<endl;


    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"Segment Tree MIN :"<<endl;
    datos[2]->build(v1,0,v1.size()-1,1);
    cout<<"------------------------------------------------"<<endl;
    datos[2]->print();    
    cout<<"------------------------------------------------"<<endl;
    int min=datos[2]->query(0,v1.size()-1,0,1,1);
    cout<<"Resultado : "<<min<<endl;



    return 0;
}   


