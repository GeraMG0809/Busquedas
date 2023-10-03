#include"ColaEstatica.cpp"



int main(){
    ColaEstatica<Solicitud> solicitudes;
    int opcion;
    do {
        std::cout << "\t \n === MENU ===" << std::endl;
        std::cout << "1. Dar de alta solicitud " << std::endl;
        std::cout << "2. Elaborar constancia " <<std::endl;
        std::cout << "3. Buscar solicitud " <<std::endl;
        std::cout << "4. Salir" << std::endl;
        std::cout << "Ingrese la opcion: ";
        std::cin >> opcion;
        std::cin.ignore();
        switch(opcion){
            case 1:{
                    Solicitud nueva_solicitud;
                    std::cin >> nueva_solicitud;
                    solicitudes.Queue(nueva_solicitud);
                    std::cout << "Solicitud encolada exitosamente." << std::endl;
                    break;
                }
            case 2:{
                    if(!solicitudes.Vacia()){
                        Solicitud solicitud_actual = solicitudes.Front();
                        std::cout << "=== CONSTANCIA ===" << std::endl;
                        std::cout << solicitud_actual << std::endl;
                        solicitudes.Dequeue();
                        std::cout << "Solicitud eliminada de la cola exitosamente." << std::endl;
                    } else {
                        std::cout << "No hay solicitudes pendientes." << std::endl;
                    }
                    break;
                }
            case 3:{
                if(solicitudes.Vacia()){
                    std::cout<<"Cola vacia... nada en espera..."<<std::endl;
                }else{

                    Solicitud solicitud_bucar;
                    std::string name;
                    std::cout<<"ingrese el nombre de la solicitud ";
                    std::cin>>name;
                    solicitud_bucar.setNombre(name);
                    int pos = solicitudes.busquedaLineal(solicitud_bucar);
                    std::cout<<"Hay "<<pos<<" restantes..."<<std::endl;
                    }     
                }
            case 4:{
                std::cout <<" Saliendo del programa...";
                break;
                }

            default:{
                std::cout<<"\nOpcion invalida "<<std::endl;
                break;
            }
        }
    }while(opcion != 4);
}