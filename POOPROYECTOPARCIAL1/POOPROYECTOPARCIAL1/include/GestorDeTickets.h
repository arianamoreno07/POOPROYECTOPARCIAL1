/**
 * @file GestorDeTickets.h
 * @brief Define la clase GestorDeTickets, responsable de la administración de la colección de tickets.
 *
 * Esta clase proporciona la interfaz para agregar, eliminar, buscar, editar y listar
 * todos los objetos Ticket almacenados en la aplicación.
 *
 * @author Ariana Moreno Jimenez
 * @date 2025-09-30
 */
#pragma once
#include "Prerequisites.h"
#include "Ticket.h"


 /**
  * @class GestorDeTickets
  * @brief Clase administradora que actúa como repositorio para todos los objetos Ticket.
  *
  * Utiliza un contenedor std::vector para almacenar las instancias de Ticket.
  */
class GestorDeTickets {

private:

	/**
	 * @brief Contenedor interno que almacena todos los objetos Ticket del sistema.
	 * Se accede a través de los métodos públicos de la clase.
	 */
	std::vector<Ticket> tickets;

public:
	
	// CRUD Y FUNCIONALIDAD PRINCIPAL

	/**
	 * @brief Agrega un nuevo Ticket a la colección.
	 *
	 * El ticket se añade al final del vector interno.
	 *
	 * @param[in] ticket El objeto Ticket a ser agregado (se agrega por copia).
	 * @return void
	 */
	void agregarTicket(const Ticket& ticket) {
		tickets.push_back(ticket);
	}

	/**
	 * @brief Elimina un Ticket de la colección basado en su ID único.
	 *
	 * Itera sobre la lista hasta encontrar la coincidencia de ID y la elimina.
	 *
	 * @param[in] id El ID del ticket a eliminar.
	 * @return bool Retorna true si el ticket fue encontrado y eliminado exitosamente,
	 * o false si no se encontró ningún ticket con ese ID.
	 */
	bool eliminarTicket(const std::string& id) {
		for (auto it = tickets.begin(); it != tickets.end(); ) {
			if (it->getID() == id) {
				it = tickets.erase(it); 
				return true;
			}
			else {
				++it;
			}
		}
		return false;
	}


	/**
	 * @brief Edita el título, la descripción y el estado de un Ticket existente.
	 *
	 * Internamente usa el método 'buscarTicket' para localizar el elemento.
	 * Si el ticket no existe, la función no hace nada.
	 *
	 * @param[in] id El ID del ticket a modificar.
	 * @param[in] nuevoTitulo El nuevo título a asignar.
	 * @param[in] nuevaDescripcion La nueva descripción a asignar.
	 * @param[in] nuevoEstado El nuevo estado (e.g., Estado::EnProceso).
	 * @return void
	 */
	void editarTicket(const std::string& id, const std::string& nuevoTitulo, const std::string& nuevaDescripcion, Estado nuevoEstado) {
		Ticket* ticket = buscarTicket(id);
		if (ticket) {
			ticket->setTitulo(nuevoTitulo);
			ticket->setDescripcion(nuevaDescripcion);
			ticket->setEstado(nuevoEstado);
		}
	}


	/**
	 * @brief Modifica únicamente el estado de un Ticket específico.
	 *
	 * @param[in] id El ID del ticket cuyo estado se va a cambiar.
	 * @param[in] nuevoEstado El nuevo estado a asignar.
	 * @return void
	 */
	void cambiarEstadoTicket(const std::string& id, Estado nuevoEstado) {
		Ticket* ticket = buscarTicket(id);
		if (ticket) {
			ticket->setEstado(nuevoEstado);
		}
	}

	/**
	 * @brief Busca un Ticket por su ID y devuelve un puntero al objeto.
	 *
	 * @param[in] id El ID único del ticket a buscar.
	 * @return Ticket* Un puntero al objeto Ticket si es encontrado, o nullptr si no existe.
	 */
	Ticket* buscarTicket(const std::string& id) {
		for (auto& ticket : tickets) {
			if (ticket.getID() == id) {
				return &ticket;
			}
		}
		return nullptr;
	}

	/**
	 * @brief Imprime todos los tickets almacenados en la colección a la consola (std::cout).
	 *
	 * Llama al método 'toString()' de cada Ticket para formatear la salida.
	 * Si la colección está vacía, imprime un mensaje de aviso.
	 *
	 * @return void
	 */
	void listarTickets() const {
		if (tickets.empty()) {
			std::cout << "No hay tickets disponibles." << std::endl;
			return;
		}
		for (const auto& ticket : tickets) {
			std::cout << ticket.toString() << std::endl;
		}
	}


	std::vector<Ticket>& getTickets() { return tickets; }
};