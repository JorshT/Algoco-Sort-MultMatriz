#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <chrono>
using namespace std;

//Funciones sorting


//Selection Sort

void selection_sort(vector<int>& arr,int n){
    for(int i=0;i<n-1;i++){
        int jmin = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[jmin]){
                jmin = j;
            }
        }
        if(jmin!=i){
            int aux = arr[jmin];
            arr[jmin] = arr[i];
            arr[i]=aux;
        }
    }
}

//Funcion Merge

void merge(vector<int>& array,int inicio,int mitad,int final){
    int i,j,k;
    int elementosIzq = mitad-inicio + 1;
    int elementosDer = final-mitad;
    vector<int> izquierda(elementosIzq);
    vector<int> derecha(elementosDer);

    for(int i=0;i < elementosIzq;i++){
        izquierda[i] = array[inicio+i];
    }

    for(int j=0;j<elementosDer;j++){
        derecha[j] = array[mitad+1+j];
    }
    i=0;
    j=0;
    k=inicio;

    while(i< elementosIzq && j<elementosDer){
        if(izquierda[i]<=derecha[j]){
            array[k] = izquierda[i];
            i++;
        }
        else{
            array[k] = derecha[j];
            j++;
        }
        k++;
    }

    while(j<elementosDer){
        array[k] = derecha[j];
        j++;
        k++;
    }

    while(i<elementosIzq){
        array[k] = izquierda[i];
        i++;
        k++;
    }
}



//Merge Sort

void merge_sort(vector<int>& array,int inicio,int final){
    if(inicio < final){
        int mitad = inicio + (final-inicio)/2;
        merge_sort(array,inicio,mitad);
        merge_sort(array,mitad+1,final);
        merge(array,inicio,mitad,final);
    }
}

//Intercambiar variables

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}


//Particion

int part(vector<int> & array,int inicio,int final){
    int pivote = array[final];
    int i=inicio-1;

    for(int j=inicio;j<=final-1;j++){
        if(array[j]<=pivote){
            i++;
            swap(array[i],array[j]);
        }
    }
    swap(array[i+1],array[final]);
    return i+1;
}

//Quick sort

void quick_sort(vector<int>& array,int inicio, int final){
    if (inicio<final){
        int ind = part(array,inicio,final);

        quick_sort(array,inicio,ind-1);
        quick_sort(array,ind+1,final);
    }
}


//Codigo principal

int main(){

    ifstream fp("datasets/large_lists_to_sort.txt");
    
    if(!fp.is_open()){
        cout<<"Error al abrir el archivo";
        return 1;
    }
    int n_elements;
    int elem;
    fp>>n_elements;
    vector<int> array;

    for(int i=0;i<n_elements;i++){
        fp>>elem;
        array.push_back(elem);
    }
    fp.close();
    
    auto start = chrono::high_resolution_clock::now();
    //selection_sort(array,n_elements);
    //merge_sort(array,0,n_elements-1);
    //quick_sort(array,0,n_elements-1);
    sort(array.begin(),array.end());
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duracion = end-start;

    //Escritura de archivos
    ofstream fp_w("Salida_sort.txt");
    cout<<"Ha tardado: "<<duracion.count()<<" segundos en ordenar"<<endl;
    if(!fp_w){
        cout<<"Error al abrir el archivo"<<endl;
        return 1;
    }
    
    cout<<"Escribiendo la salida..."<<endl;
    for(int i=0;i<n_elements;i++){
        fp_w<<array[i];
        fp_w<<"\n";
    }
    fp_w.close();
    cout<<"Salida escrita correctamente :)"<<endl;
    
}