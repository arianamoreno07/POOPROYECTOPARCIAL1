
/**
 * @file main.cpp
 * @brief Contiene la función principal (main) que implementa la interfaz de línea de comandos
 * para el sistema de Gestión de Tickets.
 *
 * Se encarga de la interacción con el usuario, mostrando el menú y llamando a los métodos
 * de la clase GestorDeTickets.
 *
 * @author Ariana Moreno Jimenez
 * @date 2025-09-30
 */
#include "Prerequisites.h"
#include "Ticket.h"
#include "GestorDeTickets.h"

 /**
  * @brief Función principal del programa.
  *
  * Implementa el bucle principal del menú para la interacción del usuario y la gestión de tickets.
  *
  * @return int Retorna 0 al finalizar la ejecución exitosamente.
  */
int
main() {

	// Inicializa la clase GestorDeTickets que almacena y administra todos los tickets.
	GestorDeTickets gestor;

	int opcion = 0;

	// Bucle principal del programa: se ejecuta hasta que el usuario elija la opción '6' (Salir).
	while (opcion != 6) {

		// Muestra el menú de opciones al usuario.
		std::cout << "Menu de Gestion de Tickets\n";
		std::cout << "1. Agregar Ticket\n";
		std::cout << "2. Listar Tickets\n";
		std::cout << "3. Editar Ticket\n";
		std::cout << "4. Eliminar Ticket\n";
		std::cout << "5. Cambiar Estado de Ticket\n";
		std::cout << "6. Salir\n";
		std::cout << "Seleccione una opcion: ";
		std::cin >> opcion;
		std::cin.ignore(); // Limpia el buffer después de leer el entero.

		if (opcion == 1) {

			// AGREGAR TICKET
			std::string id, titulo, descripcion; 
			std::cout << "Ingrese ID del ticket: "; std::getline(std::cin, id);
			std::cout << "Ingrese titulo del ticket: "; std::getline(std::cin, titulo);
			std::cout << "Ingrese descripcion del ticket: "; std::getline(std::cin, descripcion);
			

			// Se crea un nuevo objeto Ticket con el estado inicial 'Pendiente'.
			gestor.agregarTicket(Ticket(id, titulo, descripcion, Estado::Pendiente));
			std::cout << "Ticket agregado exitosamente.\n";

		}
		else if (opcion == 2) {
			
			// LISTAR TICKETS 
			gestor.listarTickets();

		} else if (opcion == 3) {

			std::string id, titulo, descripcion; 
			std::cout << "ID del ticket a editar: "; std::getline(std::cin, id);
			std::cout << "Nuevo titulo: "; std::getline(std::cin, titulo);
			std::cout << "Nueva descripcion: "; std::getline(std::cin, descripcion);


			// Edita el ticket. Mantiene el estado actual del ticket, pero se podría solicitar.
			// NOTA: Actualmente se está forzando a 'Pendiente', lo cual podría ser un error de lógica.
			// Se usa el estado Pendiente como marcador de posición.
			gestor.editarTicket(id, titulo, descripcion, Estado::Pendiente);
			std::cout << "Ticket editado.\n";


		} else if (opcion == 4) {

			// ELIMINAR TICKET 
			std::string id;
			std::cout << "ID del ticket a eliminar: "; std::getline(std::cin, id);
			gestor.eliminarTicket(id);
			std::cout << "Ticket eliminado.\n";

		} else if (opcion == 5) {

			// CAMBIAR ESTADO DE TICKET 
			std::string id;
			std::cout << "ID del ticket para cambiar estado: "; std::getline(std::cin, id);
			std::cout << "Seleccione nuevo estado (1: Pendiente, 2: En Proceso, 3: Completado): ";
			int est; std::cin >> est; std::cin.ignore();

			// Lógica para mapear la opción numérica a la enumeración Estado.
			Estado nuevo = Estado::Pendiente;
			if (est == 2) nuevo = Estado::EnProceso;
			else if (est == 3) nuevo = Estado::Completado;
			gestor.cambiarEstadoTicket(id, nuevo);

		} else if (opcion == 6) {

			std::cout << "Saliendo del programa.\n";
		} else { 
			std::cout << "Opcion invalida.\n";
		}
	}

	return 0;
			
};