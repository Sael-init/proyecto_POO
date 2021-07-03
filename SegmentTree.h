#include <bits/stdc++.h>

using namespace std;


//template <typename T>
class SegmentTree{
public:
    vector<int> st;
    int n;
    
    SegmentTree(int n_t){ st.resize(n_t*4);n=n_t;}

    void get_size(){
        cout<<n<<endl;
    }
    void print(){
        for(auto x:st){
            cout<<x<<",";
        }
        cout<<"finale"<<'\n';
    }

    void build();
};

class ST_min:public SegmentTree{
    public:    
    ST_min(int n_t):SegmentTree(n_t){}
    
    void build(vector<int> arr,int left,int right,int id){
        if(left==right){
            st[id-1]=arr[left];
            //cout<<"posicion :"<<id<<", valor : "<<arr[left]<<endl;
            return;
        }
        int medio;
        medio=(right+left)/2;

        build(arr,left,medio,id*2);
        build(arr,medio+1,right,(id*2)+1);
        st[id-1]=( st[(id*2)-1] < st[(id*2)] ) ? st[(id*2)-1] : st[id*2];
    }

    int query(int left,int right,int qleft,int qright,int qid){
        if(left >= qleft && right <= qright){
            cout<<"Inclusion : ["<<left<<","<<right<<"]"<<" ⊂ ["<<qleft<<","<<qright<<"]"<<" -> "<<qid-1<< ","<<st[qid-1]<<endl; 
            return st[qid-1];
        }//caso 3 : Inclusion 
        if( (qright < left) || (qleft > right)){ 
            cout<<"No intersectan : ["<<qleft<<","<<qright<<"]"<<" -∩ ["<<left<<","<<right<<"]"<<endl;
            return 100000;
        }// caso1 : no intersecta
        int medio=(right+left)/2;
        auto val1=query(left,medio,qleft,qright,qid*2);
        auto val2=query(medio+1,right,qleft,qright,(qid*2)+1);
        return (val1 < val2)?val1:val2;
    }
};

class ST_max:public SegmentTree{
    public:    
    ST_max(int n_t):SegmentTree(n_t){}
    void build(vector<int> arr,int left,int right,int id){
        if(left==right){
            st[id-1]=arr[left];
            //cout<<"posicion :"<<id<<", valor : "<<arr[left]<<endl;
            return;
        }
        int medio;
        medio=(right+left)/2;

        build(arr,left,medio,id*2);
        build(arr,medio+1,right,(id*2)+1);
        st[id-1]=( st[(id*2)-1] > st[(id*2)] ) ? st[(id*2)-1] : st[id*2];
    }

    int query(int left,int right,int qleft,int qright,int qid){
        if(left >= qleft && right <= qright){
            cout<<"Inclusion : ["<<left<<","<<right<<"]"<<" ⊂ ["<<qleft<<","<<qright<<"]"<<" -> "<<qid-1<< ","<<st[qid-1]<<endl; 
            return st[qid-1];
        }//caso 3 : Inclusion 
        if( (qright < left) || (qleft > right)){ 
            cout<<"No intersectan : ["<<qleft<<","<<qright<<"]"<<" -∩ ["<<left<<","<<right<<"]"<<endl;
            return -10000;
        }// caso1 : no intersecta
        int medio=(right+left)/2;
        auto val1=query(left,medio,qleft,qright,qid*2);
        auto val2=query(medio+1,right,qleft,qright,(qid*2)+1);
        return (val1 > val2)?val1:val2;
    }
};

class ST_sum:public SegmentTree{
    public:    
    ST_sum(int n_t):SegmentTree(n_t){}
    void build(vector<int> arr,int left,int right,int id){
        if(left==right){
            st[id-1]=arr[left];
            //cout<<"posicion :"<<id<<", valor : "<<arr[left]<<endl;
            return;
        }
        int medio;
        medio=(right+left)/2;

        build(arr,left,medio,id*2);
        build(arr,medio+1,right,(id*2)+1);
        st[id-1]=st[(id*2)-1] + st[(id*2)];
    }

    int query(int left,int right,int qleft,int qright,int qid){
        if(left >= qleft && right <= qright){
            cout<<"Inclusion : ["<<left<<","<<right<<"]"<<" ⊂ ["<<qleft<<","<<qright<<"]"<<" -> "<<qid-1<< ","<<st[qid-1]<<endl; 
            return st[qid-1];
        }//caso 3 : Inclusion 
        if( (qright < left) || (qleft > right)){ 
            cout<<"No intersectan : ["<<qleft<<","<<qright<<"]"<<" -∩ ["<<left<<","<<right<<"]"<<endl;
            return 0;
        }// caso1 : no intersecta
        int medio=(right+left)/2;
        auto val1=query(left,medio,qleft,qright,qid*2);
        auto val2=query(medio+1,right,qleft,qright,(qid*2)+1);
        return val1+val2;
    }
};
