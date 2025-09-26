#include "Prerequisites.h"
#include "Ticket.h"
#include "GestorDeTickets.h"

int
main() {

	GestorDeTickets gestor;

	int opcion = 0;

	while (opcion != 6) {

		std::cout << "Menu de Gestion de Tickets\n";
		std::cout << "1. Agregar Ticket\n";
		std::cout << "2. Listar Tickets\n";
		std::cout << "3. Editar Ticket\n";
		std::cout << "4. Eliminar Ticket\n";
		std::cout << "5. Cambiar Estado de Ticket\n";
		std::cout << "6. Salir\n";
		std::cout << "Seleccione una opcion: ";
		std::cin >> opcion;
		std::cin.ignore();

		if (opcion == 1) {

			std::string id, titulo, descripcion, fecha;
			std::cout << "Ingrese ID del ticket: "; std::getline(std::cin, id);
			std::cout << "Ingrese titulo del ticket: "; std::getline(std::cin, titulo);
			std::cout << "Ingrese descripcion del ticket: "; std::getline(std::cin, descripcion);
			std::cout << "Ingrese fecha del ticket: "; std::getline(std::cin, fecha);
			gestor.agregarTicket(Ticket(id, titulo, descripcion, "Pendiente", fecha, 0.0));
			std::cout << "Ticket agregado exitosamente.\n";

		}
		else if (opcion == 2) {
			
			gestor.listarTickets();

		} else if (opcion == 3) {

			std::string id, titulo, descripcion, fecha;
			std::cout << "ID del ticket a editar: "; std::getline(std::cin, id);
			std::cout << "Nuevo titulo: "; std::getline(std::cin, titulo);
			std::cout << "Nueva descripcion: "; std::getline(std::cin, descripcion);
			std::cout << "Nueva fecha: "; std::getline(std::cin, fecha);
			gestor.editarTicket(id, titulo, descripcion, Estado::Pendiente, 0.0, false);
			std::cout << "Ticket editado.\n";

		}
		else if (opcion == 4) {
			std::string id;
			std::cout << "ID del ticket a eliminar: "; std::getline(std::cin, id);
			gestor.eliminarTicket(id);
			std::cout << "Ticket eliminado.\n";

		}
		else if (opcion == 5) {
			std::string id;
			std::cout << "ID del ticket para cambiar estado: "; std::getline(std::cin, id);
			std::cout << "Seleccione nuevo estado (1: Pendiente, 2: En Proceso, 3: Completado): ";
			int est; std::cin >> est; std::cin.ignore();
			Estado nuevo = Estado::Pendiente;
			if (est == 2) nuevo = Estado::EnProceso;
			else if (est == 3) nuevo = Estado::Completado;
			gestor.cambiarEstadoTicket(id, nuevo);

		}else if (opcion == 6) {
			std::cout << "Saliendo del programa.\n";
		}
		else {
			std::cout << "Opcion invalida.\n";
		}
	}

	return 0;

};