/**
 * @file GestorDeTickets.h
 * @brief Define la clase GestorDeTickets, responsable de la administraci�n de la colecci�n de tickets.
 *
 * Esta clase proporciona la interfaz para agregar, eliminar, buscar, editar y listar
 * todos los objetos Ticket almacenados en la aplicaci�n.
 *
 * @author Ariana Moreno Jimenez
 * @date 2025-09-30
 */
#pragma once
#include "Prerequisites.h"
#include "Ticket.h"


 /**
  * @class GestorDeTickets
  * @brief Clase administradora que act�a como repositorio para todos los objetos Ticket.
  *
  * Utiliza un contenedor std::vector para almacenar las instancias de Ticket.
  */
class GestorDeTickets {

private:

	/**
	 * @brief Contenedor interno que almacena todos los objetos Ticket del sistema.
	 */
	std::vector<Ticket> tickets;

	/**
	* @brief Contador que lleva el registro del proximo ID disponible para asignar a un nuevo Ticket.
	* Se inicializa en 2000 y se incrementa autom�ticamente con cada nuevo ticket.
	*/
	int 
	proximoID = 2000; 

	/**
	* @brief Genera el siguiente ID de ticket como una cadena numerica. 
	* Utiliza el contador 'proximoID' y lo incrementa despu�s de cada llamada.
	* @return std::string El ID generado para el nuevo ticket compuesto solo de numeros. 
	*/
	std::string generarProximoID() {
		std::string id = std::to_string(proximoID);
		proximoID++;
		return id;

	}

public:
	
	/**
	 * @brief Constructor por defecto de la clase GestorDeTickets.
	 *
	 * Inicializa la colecci�n de tickets como un vector vac�o.
	 */
	GestorDeTickets() = default; // Opci�n concisa usando '= default;'
	
	// CRUD Y FUNCIONALIDAD PRINCIPAL


	/**
	 * @brief Agrega un nuevo Ticket a la colecci�n, generando su ID autom�ticamente.
	 *
	 * El ticket se a�ade al final del vector interno con el estado inicial 'Pendiente'.
	 *
	 * @param[in] titulo El t�tulo descriptivo del ticket.
	 * @param[in] descripcion El detalle completo del problema o tarea.
	 * @return void
	 */
	void 
		agregarTicket(const std::string& titulo, const std::string& descripcion) {
		std::string id = generarProximoID();
		Ticket nuevoTicket(id, titulo, descripcion, Estado::Pendiente);
		tickets.push_back(nuevoTicket);
	}

	/**
	 * @brief Elimina un Ticket de la colecci�n basado en su ID �nico.
	 *
	 * Itera sobre la lista hasta encontrar la coincidencia de ID y la elimina.
	 *
	 * @param[in] id El ID del ticket a eliminar.
	 * @return bool Retorna true si el ticket fue encontrado y eliminado exitosamente,
	 * o false si no se encontr� ning�n ticket con ese ID.
	 */
	bool 
		eliminarTicket(const std::string& id) {
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
	 * @brief Edita el t�tulo, la descripci�n y el estado de un Ticket existente.
	 *
	 * Si el ticket existe, actualiza sus campos. El estado se mantiene igual si no se modifica.
	 *
	 * @param[in] id El ID del ticket a modificar.
	 * @param[in] nuevoTitulo El nuevo t�tulo a asignar.
	 * @param[in] nuevaDescripcion La nueva descripci�n a asignar.
	 * @param[in] nuevoEstado El nuevo estado (se suele pasar el estado actual si solo se cambian t�tulo/descripci�n).
	 * @return void
	 */
	void 
		editarTicket(const std::string& id, const std::string& nuevoTitulo, const std::string& nuevaDescripcion, Estado nuevoEstado) {
		Ticket* ticket = buscarTicket(id);
		if (ticket) {
			ticket->setTitulo(nuevoTitulo);
			ticket->setDescripcion(nuevaDescripcion);
			ticket->setEstado(nuevoEstado);
		}
	}


	/**
	 * @brief Modifica �nicamente el estado de un Ticket espec�fico.
	 *
	 * @param[in] id El ID del ticket cuyo estado se va a cambiar.
	 * @param[in] nuevoEstado El nuevo estado a asignar.
	 * @return void
	 */
	void 
		cambiarEstadoTicket(const std::string& id, Estado nuevoEstado) {
		Ticket* ticket = buscarTicket(id);
		if (ticket) {
			ticket->setEstado(nuevoEstado);
		}
	}

	/**
	 * @brief Busca un Ticket por su ID y devuelve un puntero al objeto.
	 *
	 * @param[in] id El ID �nico del ticket a buscar.
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
	 * @brief Imprime todos los tickets almacenados en la colecci�n a la consola (std::cout).
	 *
	 * Llama al m�todo 'toString()' de cada Ticket para formatear la salida,
	 * usando separadores para mejorar la legibilidad.
	 * Si la colecci�n est� vac�a, imprime un mensaje de aviso.
	 *
	 * @return void
	 */
	void 
		listarTickets() const {
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