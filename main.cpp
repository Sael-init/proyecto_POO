#include "SegmentTree.h"


int main(){

    vector<int> v1={-1,2,5,0};
    cout<<"------------------------------------------------"<<endl;
    cout<<"Segment Tree SUMA :"<<endl;
    ST_sum ST1(4);
    ST1.build(v1,0,v1.size()-1,1);
    cout<<"------------------------------------------------"<<endl;
    ST1.print();    
    cout<<"------------------------------------------------"<<endl;
    int suma=ST1.query(0,v1.size()-1,0,1,1);
    cout<<"Resultado : "<<suma<<endl;

    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"Segment Tree MAX :"<<endl;
    ST_max ST2(4);
    ST2.build(v1,0,v1.size()-1,1);
    cout<<"------------------------------------------------"<<endl;
    ST2.print();    
    cout<<"------------------------------------------------"<<endl;
    int max=ST2.query(0,v1.size()-1,0,1,1);
    cout<<"Resultado : "<<max<<endl;


    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
    cout<<"Segment Tree MIN :"<<endl;
    ST_min ST3(4);
    ST3.build(v1,0,v1.size()-1,1);
    cout<<"------------------------------------------------"<<endl;
    ST3.print();    
    cout<<"------------------------------------------------"<<endl;
    int min=ST3.query(0,v1.size()-1,0,1,1);
    cout<<"Resultado : "<<min<<endl;



    return 0;
}   


