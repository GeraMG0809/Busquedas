#include"Solicitud.cpp"


#define TAM 50


template<class T>
class ColaEstatica{

    private: 
        T datos[TAM];
        int ult;
        bool Inserta(T,int);
        bool Elimina(int);
        int Primero();
        int Ultimo();
        void Imprime();
    
    public:
        ColaEstatica():ult(-1){}
        bool Vacia();
        bool Llena();
        bool Queue(T);
        bool Dequeue();
        T Front();
        int busquedaLineal(T);
        int busquedaBinaria(T);



};

template<class T>
bool ColaEstatica<T>::Inserta(T dat, int pos){
    if(Llena() || pos<0 || pos>ult+1){
        std::cout<<"Cola llena... Imposible insertar\n";
        return false;
    }
    int i = ult +1;
    while (i>pos){
        datos[i] = datos[i-1];
        i--;
    }
    datos[pos]= dat;
    ult++;
    return true;
}


template<class T>
bool ColaEstatica<T>::Elimina(int pos){
    if (Vacia()){
        std::cout<<"Imposible eliminar...Cola vacia\n";
    }
    int i = pos;
    while (i <ult){
        datos[i] = datos[i+1];
        i++;
    }
    ult--;
    return true;
    
}

template<class T>
int ColaEstatica<T>::Primero(){
    if(Vacia()){
        return -1;
    }
    return 0;
}

template<class T>
int ColaEstatica<T>::Ultimo(){
    if (Vacia()){
        return-1;
    }
    return ult;
}


template<class T>
bool ColaEstatica<T>::Vacia(){
    if(ult == -1){
        return true;
    }else{
        return false;
    }
}

template<class T>
bool ColaEstatica<T>::Llena(){
    if(ult == TAM-1){
        return true;
    }else{
        return false;
    }
}


template<class T>
void ColaEstatica<T>::Imprime(){
    if(!Vacia()){
        for (size_t i = 0; i < ult; i++){
            T datos = datos[i];
            std::cout<<datos<<std::endl;
        } 
    }
}


template<class T>
bool ColaEstatica<T>::Queue(T dat){
    if (Llena()){
        return false;
    }
    if(Vacia()){
        Inserta(dat,0);
    }else{
        Inserta(dat,Ultimo()+1);
    }
    return true;
}


template<class T>
bool ColaEstatica<T>::Dequeue(){
    if(Vacia()){
        return false;
    }else{
        Elimina(Primero());
    }
    return true;
}

template<class T>
T ColaEstatica<T>::Front(){
    T datoVacio;
    if(Vacia()){
        std::cout<<"Nada en el frente\n";
        return datoVacio;
    }else{
        T dat = datos[Primero()];
        return dat;
    }
}


template<class T>
int ColaEstatica<T>::busquedaLineal(T dat){
    if (Vacia()){
        return 0;
    }else{
        int i = ult;
        int x;
       while (i > ult){
            if(datos[i] == dat){
                return x;
            }
            x++;
       }
    }
}


template<class T>
int ColaEstatica<T>::busquedaBinaria(T dat){
    if(Vacia()){
        return 0;
    }else{
        int i =0;
        int j = ult;
        while(i<j){
            int medio = (i+j)/2;
            if(datos[medio] == dat){
                return medio;
            }else{
                if(dat == datos[medio]){
                    j = medio - 1;
                }else{
                    i = medio +1;
                }
            }
        }
    }
}