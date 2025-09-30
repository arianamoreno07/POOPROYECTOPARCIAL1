/**
 * @file Ticket.h
 * @brief Define la clase Ticket, que representa un elemento o una tarea dentro del sistema.
 *
 * Un Ticket almacena informaci�n relevante como un identificador �nico, un t�tulo,
 * la descripci�n, su estado actual y la fecha de creaci�n.
 *
 * @author Ariana Moreno Jimenez
 * @date 2025-09-30
 */
#pragma once

#include "Prerequisites.h" // Se asume que aqu� est�n definidos 'Estado' y 'Fecha'


 /**
  * @class Ticket
  * @brief Clase fundamental para la gesti�n de elementos de trabajo o incidentes.
  *
  * Cada instancia de Ticket es inmutable en cuanto a su ID, pero se puede
  * modificar su estado, t�tulo y descripci�n.
  */
class Ticket {

public: 
	
	/**
	 * @brief Constructor por defecto de la clase Ticket.
	 *
	 * Inicializa todos los miembros con valores vac�os o predeterminados:
	 * ID, t�tulo, descripci�n = ""
	 * estado = Estado::Pendiente
	 * fecha = {0, 0, 0}
	 */
	Ticket() : ID(""), titulo(""), descripcion(""), estado(Estado::Pendiente), fecha{ 0, 0, 0 } {
		// Se asume que aqu� est�n definidos 'Estado' y 'Fecha'

	}

	/**
	 * @brief Constructor parametrizado para crear un Ticket completamente inicializado.
	 *
	 * Tambi�n llama a 'fecha.getFecha()' para registrar la fecha de creaci�n del sistema.
	 *
	 * @param m_ID El identificador �nico del ticket.
	 * @param m_titulo El t�tulo descriptivo del ticket.
	 * @param m_descripcion El detalle completo del problema o tarea.
	 * @param m_estado El estado inicial del ticket.
	 */
	Ticket(std::string m_ID, std::string m_titulo, std::string m_descripcion, Estado m_estado)
		: ID(m_ID), titulo(m_titulo), descripcion(m_descripcion), estado(m_estado) {

		
		fecha.getFecha(); // Almacena la fecha y hora de creaci�n.
	}

	// GETTERS

	/**
	 * @brief Obtiene el ID �nico del ticket.
	 * @return std::string El identificador del ticket.
	 */
	std::string getID() const { return ID; }

	/**
	 * @brief Obtiene el t�tulo del ticket.
	 * @return std::string El t�tulo del ticket.
	 */
	std::string getTitulo() const { return titulo; }

	/**
	 * @brief Obtiene la descripci�n detallada del ticket.
	 * @return std::string La descripci�n del ticket.
	 */
	std::string getDescripcion() const { return descripcion; }

	/**
	 * @brief Obtiene el estado actual del ticket.
	 * @return Estado El estado del ticket (Pendiente, EnProceso, Completado).
	 */
	Estado getEstado() const { return estado; }
	
	/**
	 * @brief Obtiene la fecha de creaci�n del ticket como una cadena de texto.
	 * @return std::string La fecha de creaci�n en formato DD/MM/AAAA.
	 */
	std::string getFecha() const { return fecha.toString(); }
	
	// SETTERS

	/**
	 * @brief Establece un nuevo t�tulo para el ticket.
	 * @param nuevoTitulo El nuevo t�tulo a asignar.
	 * @return void
	 */
	void setTitulo(const std::string& nuevoTitulo) { titulo = nuevoTitulo; }

	/**
	 * @brief Establece una nueva descripci�n para el ticket.
	 * @param nuevaDescripcion La nueva descripci�n a asignar.
	 * @return void
	 */
	void setDescripcion(const std::string& nuevaDescripcion) { descripcion = nuevaDescripcion; }

	/**
	 * @brief Actualiza el estado del ticket.
	 * @param m_estado El nuevo estado (e.g., Estado::Completado).
	 * @return void
	 */
	void setEstado(Estado m_estado) { estado = m_estado; }


	// UTILIDAD

	/**
	 * @brief Genera una representaci�n legible del Ticket en una cadena de texto.
	 *
	 * Incluye todos los campos: ID, T�tulo, Descripci�n, Estado (en texto) y Fecha.
	 *
	 * @return std::string La representaci�n completa del ticket formateada.
	 */
	std::string toString() const {
		
		return "ID: " + ID + "\nTitulo: " + titulo + "\nDescripcion: " + descripcion + "\nEstado: " + estadoToString(estado) + "\nFecha: " + fecha.toString() + "\n";
	}

private:
	std::string ID; //< Identificador �nico del ticket (e.g., "T-001").
	std::string titulo; //< Resumen conciso de la tarea
	std::string descripcion; //< Resumen conciso de la tarea
	Estado estado; //< El estado actual del ticket (usa la enum Estado).

	Fecha fecha; //< Fecha de creaci�n del ticket.

};