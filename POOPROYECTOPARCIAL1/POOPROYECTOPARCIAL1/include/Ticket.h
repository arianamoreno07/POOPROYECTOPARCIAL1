#pragma once

#include "Prerequisites.h"

class Ticket {

public:
	
	Ticket() : ID(""), titulo(""), descripcion(""), estado(Estado::Pendiente), fecha{ 0, 0, 0 } {
		
	}

	
	Ticket(std::string m_ID, std::string m_titulo, std::string m_descripcion, Estado m_estado)
		: ID(m_ID), titulo(m_titulo), descripcion(m_descripcion), estado(m_estado) {

		
		fecha.getFecha();
	}

	
	std::string getID() const { return ID; }
	std::string getTitulo() const { return titulo; }
	std::string getDescripcion() const { return descripcion; }
	Estado getEstado() const { return estado; }
	
	std::string getFecha() const { return fecha.toString(); }
	

	void setTitulo(const std::string& nuevoTitulo) { titulo = nuevoTitulo; }
	void setDescripcion(const std::string& nuevaDescripcion) { descripcion = nuevaDescripcion; }
	void setEstado(Estado m_estado) { estado = m_estado; }


	std::string toString() const {
		
		return "ID: " + ID + "\nTitulo: " + titulo + "\nDescripcion: " + descripcion + "\nEstado: " + estadoToString(estado) + "\nFecha: " + fecha.toString() + "\n";
	}

private:
	std::string ID;
	std::string titulo;
	std::string descripcion;
	Estado estado;

	Fecha fecha; 

};