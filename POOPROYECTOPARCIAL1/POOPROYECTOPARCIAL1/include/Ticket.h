#pragma once

#include "Prerequisites.h"

class Ticket {

public:

	Ticket(std::string m_ID, std::string m_titulo, std::string m_descripcion, std::string m_estado, std::string m_fecha, double m_precio )
		: ID(m_ID), titulo(m_titulo), descripcion(m_descripcion), estado(Estado::Pendiente), fecha(m_fecha), precio(m_precio), venta(false) {
	}

	std::string getID() const { return ID; }
	std::string getTitulo() const { return titulo; }
	std::string getDescripcion() const { return descripcion; }
	Estado getEstado() const { return estado; }
	std::string getFecha() const { return fecha; }
	double getPrecio() const { return precio; }
	bool isVenta() const { return venta; }

	void setTitulo(const std::string& nuevoTitulo) { titulo = nuevoTitulo; }
	void setDescripcion(const std::string& nuevaDescripcion) { descripcion = nuevaDescripcion; }
	void setEstado(Estado m_estado) { estado = m_estado; }
	void setVenta(bool esVenta) { venta = esVenta; }
	void setPrecio(double nuevoPrecio) { precio = nuevoPrecio; }

	std::string toString() const {
		return "ID: " + ID + "\nTitulo: " + titulo + "\nDescripcion: " + descripcion + "\nEstado: " + estadoToString(estado) + "\nFecha: " + fecha + "\nPrecio: " + std::to_string(precio) + "\nVenta: " + (venta ? "Si" : "No") + "\n";
	}



private:
	std::string ID;
	std::string titulo;
	std::string descripcion;
	Estado estado;
	std::string fecha;

	double precio;
	bool venta;


};