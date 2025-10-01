
/**
 * @file main.cpp
 * @brief Contiene la funci�n principal (main) que implementa la interfaz de l�nea de comandos
 * para el sistema de Gesti�n de Tickets.
 *
 * Se encarga de la interacci�n con el usuario, mostrando el men� y llamando a los m�todos
 * de la clase GestorDeTickets.
 *
 * @author Ariana Moreno Jimenez
 * @date 2025-09-30
 */
#include "Prerequisites.h"
#include "Ticket.h"
#include "GestorDeTickets.h"

 /**
� * @brief Funci�n principal del programa.
� *
� * Implementa el bucle principal del men� para la interacci�n del usuario y la gesti�n de tickets,
 * haciendo uso de las funciones de utilidad para una mejor presentaci�n.
� *
� * @return int Retorna 0 al finalizar la ejecuci�n exitosamente.
� */


int
main() {

	// Inicializa la clase GestorDeTickets que almacena y administra todos los tickets.
	GestorDeTickets gestor;

	int 
	opcion = 0;

	// Bucle principal del programa: se ejecuta hasta que el usuario elija la opci�n '6' (Salir).
	while (opcion != 6) {

		// Muestra el men� de opciones al usuario.
		std::cout << "\n";
		std::cout << "--------------------------------\n";
		std::cout << "Menu de Gestion de Tickets\n";
		std::cout << "--------------------------------\n";
		std::cout << "1. Agregar Ticket\n";
		std::cout << "\n";
		std::cout << "2. Listar Tickets\n";
		std::cout << "\n";
		std::cout << "3. Editar Ticket\n";
		std::cout << "\n";
		std::cout << "4. Eliminar Ticket\n";
		std::cout << "\n";
		std::cout << "5. Cambiar Estado de Ticket\n";
		std::cout << "\n";
		std::cout << "6. Salir\n";
		std::cout << "--------------------------------\n";
		std::cout << "Seleccione una opcion: ";
		std::cin >> opcion;
		std::cin.ignore(); // Limpia el buffer despu�s de leer el entero.

		if (opcion == 1) {

			// AGREGAR TICKET
			std::string titulo, descripcion; 
			std::cout << "--------------------------------\n";
			std::cout << "\n";
			std::cout << "AGREGAR TICKET\n";
			std::cout << "\n";
			std::cout << "Ingrese titulo del ticket: "; std::getline(std::cin, titulo);
			std::cout << "\n";
			std::cout << "Ingrese descripcion del ticket: "; std::getline(std::cin, descripcion);
			std::cout << "\n";

			// Se crea un nuevo objeto Ticket con el estado inicial 'Pendiente'.
			gestor.agregarTicket(titulo, descripcion);
			std::cout << "\n";
			std::cout << "Ticket agregado exitosamente.\n";

		}
		else if (opcion == 2) {
			
			// LISTAR TICKETS 
			std::cout << "--------------------------------\n";
			std::cout << "\n";
			std::cout << "LISTA DE TICKETS\n";
			std::cout << "\n";
			gestor.listarTickets();

		} else if (opcion == 3) {

			std::string id, titulo, descripcion; 
			std::cout << "--------------------------------\n";
			std::cout << "\n";
			std::cout << "EDITAR TICKET\n";
			std::cout << "\n";
			std::cout << "ID del ticket a editar: "; std::getline(std::cin, id);

			Ticket* ticketExistente = gestor.buscarTicket(id);
			if (ticketExistente) {
				std::cout << "\n";
				std::cout << "Ticket encontrado (ID: " << id << "). Ingresa nuevos datos. \n";
				std::cout << "\n";
				std::cout << "Nuevo titulo (actual: " << ticketExistente->getTitulo() << "): "; std::getline(std::cin, titulo);
				std::cout << "\n";
				std::cout << "Nueva descripcion (actual: " << ticketExistente->getDescripcion() << "): "; std::getline(std::cin, descripcion);

				Estado estadoActual = ticketExistente->getEstado();
				gestor.editarTicket(id, titulo, descripcion, estadoActual);
				std::cout << "\nTicket editado exitosamente.\n";
			}
			else {
				std::cout << "\nNo se encontro ningun ticket con ID: " << id << ".\n";
			}
			


		} else if (opcion == 4) {

			// ELIMINAR TICKET 
			std::string id;
			std::cout << "--------------------------------\n";
			std::cout << "\n";
			std::cout << "ELIMINAR TICKET\n";
			std::cout << "\n";
			std::cout << "ID del ticket a eliminar: "; std::getline(std::cin, id);
			
			if (gestor.eliminarTicket(id)) {
				std::cout << "\nTicket con ID " << id << " eliminado exitosamente.\n";
			} else {
				std::cout << "\nNo se encontro ningun ticket con ID: " << id << ".\n";
			}

		} else if (opcion == 5) {

			// CAMBIAR ESTADO DE TICKET 
			std::string id;
			std::cout << "--------------------------------\n";
			std::cout << "\n";
			std::cout << "CAMBIAR ESTADO DE TICKET\n";
			std::cout << "\n";
			std::cout << "ID del ticket para cambiar estado: "; std::getline(std::cin, id);
			std::cout << "\n";
			std::cout << "Seleccione nuevo estado (1: Pendiente, 2: En Proceso, 3: Completado): ";

			int 
			est; std::cin >> est; std::cin.ignore();

			// L�gica para mapear la opci�n num�rica a la enumeraci�n Estado.
			Estado nuevo = Estado::Pendiente;
			if (est == 2) nuevo = Estado::EnProceso;
			else if (est == 3) nuevo = Estado::Completado;

			gestor.cambiarEstadoTicket(id, nuevo);
			std::cout << "\nEstado del ticket con ID " << id << " fue actualizado a " << estadoToString(nuevo) << ".\n";

		} else if (opcion == 6) {

			std::cout << "--------------------------------\n";
			std::cout << "Saliendo del programa.\n";
		} else { 
			std::cout << "Opcion invalida.\n";
		}
	}

	return 0;
			
};