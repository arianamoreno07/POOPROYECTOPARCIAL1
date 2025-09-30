#pragma once
#include "Prerequisites.h"
#include "Ticket.h"

class GestorDeTickets {

private:
	std::vector<Ticket> tickets;

public:
	void agregarTicket(const Ticket& ticket) {
		tickets.push_back(ticket);
	}


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

	void editarTicket(const std::string& id, const std::string& nuevoTitulo, const std::string& nuevaDescripcion, Estado nuevoEstado) {
		Ticket* ticket = buscarTicket(id);
		if (ticket) {
			ticket->setTitulo(nuevoTitulo);
			ticket->setDescripcion(nuevaDescripcion);
			ticket->setEstado(nuevoEstado);
		}
	}

	void cambiarEstadoTicket(const std::string& id, Estado nuevoEstado) {
		Ticket* ticket = buscarTicket(id);
		if (ticket) {
			ticket->setEstado(nuevoEstado);
		}
	}

	Ticket* buscarTicket(const std::string& id) {
		for (auto& ticket : tickets) {
			if (ticket.getID() == id) {
				return &ticket;
			}
		}
		return nullptr;
	}
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