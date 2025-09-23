#pragma once

#include <iostream>
#include <string>
#include <vector>


enum class Estado {
Pendiente,
EnProceso,
Completado
};

inline std::string estadoToString(Estado estado) {
		switch (estado) {
		case Estado::Pendiente: return "Pendiente";
		case Estado::EnProceso: return "En Proceso";
		case Estado::Completado: return "Completado";
		default: return "Desconocido";
		}
	}


