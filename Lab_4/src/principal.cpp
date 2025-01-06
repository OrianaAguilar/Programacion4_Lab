#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <iomanip>	  // Para setw
#include <limits>	  // Para numeric_limits
#include <fstream>	  // Para manejar archivos
#include <sstream>	  //Para manipular flujos de cadenas de texto
#include <filesystem> // Para manejar directorios y archivos

#include "../inc/ControladorUsuarios.h"
#include "../inc/ControladorVentas.h"
#include "../inc/Producto.h"
#include "../inc/Vendedor.h"
#include "../inc/ProductoEnPromocion.h"
#include "../inc/DTInfoPromocion.h"
#include "../inc/Fabrica.h"

#include <stdlib.h>

using namespace std;

bool esBisiesto(int anio)
{
	bool aux;
	aux = (anio % 4 == 0 && (!anio % 100 == 0 || anio % 400));
	return aux;
}

int diasMes(int mes, int anio)
{
	int cantDias;
	switch (mes)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		cantDias = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		cantDias = 30;
		break;
	case 2:
		if (esBisiesto(anio))
			cantDias = 29;
		else
			cantDias = 28;
		break;
	default:
		printf("Numero de mes invalido.");
	}
	return cantDias;
}

void mostrarBienvenida()
{
	cout << "\033[2J\033[1;1H"; // Secuencia de escape ANSI para limpiar la pantalla
	cout << "╔════════════════════════════════════════════════════╗\n";
	cout << "║           ¡Bienvenido a Mercado Finger!            ║\n";
	cout << "╚════════════════════════════════════════════════════╝\n\n";
}

void mostrarMenu()
{
	cout << "╔════════════════════════════════════════╗\n";
	cout << "║           Menú Principal               ║\n";
	cout << "╠════════════════════════════════════════╣\n";
	cout << "║  0. ❌ Salir                           ║\n";
	cout << "║  1. 📁 Alta de usuario                 ║\n";
	cout << "║  2. 📋 Listado de usuarios             ║\n";
	cout << "║  3. 📁 Alta de producto                ║\n";
	cout << "║  4. 🔍 Consultar producto              ║\n";
	cout << "║  5. 🎁 Crear promoción                 ║\n";
	cout << "║  6. 🔍 Consultar promoción             ║\n";
	cout << "║  7. 🛒 Realizar compra                 ║\n";
	cout << "║  8. 💬 Dejar comentario                ║\n";
	cout << "║  9. 🗑️  Eliminar comentario             ║\n";
	cout << "║ 10. 📦 Enviar producto                 ║\n";
	cout << "║ 11. 🗃️  Expediente de usuario           ║\n";
	cout << "║ 12. 🔔 Suscribirse a notificaciones    ║\n";
	cout << "║ 13. 🔍 Consultar notificaciones        ║\n";
	cout << "║ 14. 🗑️  Eliminar suscripciones          ║\n";
	cout << "║ 15. 🧪 Casos de prueba                 ║\n";
	cout << "╚════════════════════════════════════════╝\n";
}

void pedirFechaActual(int &anio, int &mes, int &dia)
{
	cout << "Antes de comenzar, por favor indique la fecha actual:\n";
	cout << "Ingrese el año: ";
	cin >> anio;

	cout << "Ingrese el mes: ";
	cin >> mes;
	while (mes > 12 || mes < 1)
	{
		cout << "Ingrese un mes válido: ";
		cin >> mes;
	}

	int cantDiasMes = 31; // Valor por defecto para establecer un límite inicial seguro
	switch (mes)
	{
	case 4:
	case 6:
	case 9:
	case 11:
		cantDiasMes = 30;
		break;
	case 2:
		if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))
		{
			cantDiasMes = 29;
		}
		else
		{
			cantDiasMes = 28;
		}
		break;
	default:
		cantDiasMes = 31;
		break;
	}

	cout << "Ingrese el día: ";
	cin >> dia;
	while (dia > cantDiasMes || dia < 1)
	{
		cout << "Ingrese un día válido: ";
		cin >> dia;
	}
}

void esperarTecla()
{
	cout << "\nPresione Enter para continuar...";
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar cualquier entrada previa
	cin.get();											 // Espera a que el usuario presione Enter
}

int main()
{

	// ** FABRICA CREACION Y GET iCONTROLADORES** //
	cout << "SE CREA LA FABRICA" << endl;
	Fabrica *factoria;
	factoria = factoria->getFabrica();
	Fabrica *factoriaFake;
	factoriaFake = factoriaFake->getFabrica();

	if (factoria == factoriaFake)
	{
		cout << "LA FABRICA ES SINGLETON" << endl;
	}
	else
		cout << "ANDA MAL" << endl;

	// ----------------------------------------------- //

	iControladorUsuarios *controladorUsuarios = factoria->getControladorUsuarios();
	iControladorVentas *controladorVentas = factoria->getControladorVentas();

	iControladorUsuarios *controladorUsuarios2 = factoria->getControladorUsuarios();
	iControladorVentas *controladorVentas2 = factoria->getControladorVentas();

	if (controladorUsuarios == controladorUsuarios2)
	{
		cout << "Controlador Ususarios ES SINGLETON" << endl;
	}

	if (controladorVentas == controladorVentas2)
	{
		cout << "Controlador Ventas ES SINGLETON" << endl;
	}

	//----------------------**MENU INTERACTIVO**----------------------//

	int anio = 0;
	int mes = 0;
	int dia = 0;

	mostrarBienvenida();
	pedirFechaActual(anio, mes, dia);

	// Creación de la fecha actual
	cout << "\nFecha actual establecida: " << setw(2) << setfill('0') << dia << "/"
		 << setw(2) << setfill('0') << mes << "/" << anio << endl;

	controladorVentas->setFechaActual(DTFecha(dia, mes, anio));
	// Aquí podrías continuar con la lógica de tu programa

	esperarTecla(); // Espera a que el usuario presione Enter

	int opcion;

	do
	{
		mostrarMenu();
		cout << "Ingrese la opción deseada: ";
		cin >> opcion;
		switch (opcion){
		case 1:
		{
			string nombreUsuario;
			cout << "Indique Nombre del Usuario nuevo" << endl;
			cin >> nombreUsuario;
			while (controladorUsuarios->existeNickname(nombreUsuario))
			{
				cout << "El nickname ya se encuentra registrado, por favor ingrese otro." << endl;
				cin >> nombreUsuario;
				cout << "Ha seleccionado Alta de usuario.\n";
			}
			string contra;
			cout << "Indique contraseña del Usuario nuevo" << endl;
			cin >> contra;
			while(contra.size()<6){
				cout<<"La contrasenia debe tener al menos 6 caracteres de largo, por favor intente nuevamente:"<<endl;
				cin>>contra;
			}
			cout << "Ingrese el anio de nacimiento:" << endl;
			int anioAlta;
			cin >> anioAlta;
			while (anioAlta < 1900 || anioAlta > 2006)
			{
				cout << "Ingrese un anio valido:" << endl;
				cin >> anioAlta;
			}
			int mesAlta;
			cout << "Ingrese el mes de nacimiento:" << endl;
			cin >> mesAlta;
			while (mesAlta > 12 || mesAlta < 1)
			{
				cout << "Ingrese un mes valido:" << endl;
				cin >> mesAlta;
			}
			int diaAlta;
			cout << "Ingrese el dia de nacimiento:" << endl;
			cin >> diaAlta;
			int cantDiasMesAlta = diasMes(mesAlta, anioAlta);
			while (diaAlta > cantDiasMesAlta || diaAlta < 1)
			{
				cout << "Ingrese un dia valido:" << endl;
				cin >> diaAlta;
			}
			cout << "¿Desea registrar un vendedor o un cliente?" << endl;
			// cin.ignore(numeric_limits<streamsize>::max(), '\n');
			char c;
			while (cin.get(c) && c != '\n')
				;
			string respuesta2;
			getline(cin, respuesta2);
			if (respuesta2 == "Cliente" || respuesta2 == "cliente")
			{
				cout << "Indique ciudad del cliente:" << endl;
				string ciudad;
				getline(cin, ciudad);
				cout << "A continuación indique su dirección:" << endl;
				cout << "Indique calle:" << endl;
				string calle;
				getline(cin, calle);
				cout << "Indique número de puerta:" << endl;
				int numPuerta;
				cin >> numPuerta;
				cout << "¿Desea confirmar el alta del cliente? Y/N" << endl;
				string respuesta;
				cin >> respuesta;
				if (respuesta == "y" || respuesta == "Y") {
					bool a = controladorUsuarios->altaCliente(nombreUsuario, contra, DTFecha(diaAlta, mesAlta, anioAlta), DTDireccion(calle, numPuerta), ciudad);
					if (a)
					{
						cout << "Su cliente fue creado" << endl;
						break;
					}
					else
					{
						cout << "No fue posible crear el cliente." << endl;
					}
				}
			}
			else if (respuesta2 == "Vendedor" || respuesta2 == "vendedor")
			{
				string codigoRut;
				cout << "Indique codigo Rut del vendedor:" << endl;
				getline(cin, codigoRut);
				while (!controladorUsuarios->esRutValido(codigoRut))
				{
					cout << "Indique un codigo de RUT valido." << endl;
					getline(cin, codigoRut);
				}
				cout << "¿Desea confirmar el alta del vendedor? Y/N" << endl;
				string respuesta;
				cin >> respuesta;
				if (respuesta == "y" || respuesta == "Y")
				{
					if (controladorUsuarios->altaVendedor(nombreUsuario, contra, DTFecha(diaAlta, mesAlta, anioAlta), codigoRut)){
						cout << "Su vendedor fue creado" << endl;
					}
				}
			}
			else
			{
				break;
			}
			break;
		}
		case 2:
		{
			controladorUsuarios->listaDeUsuarios_();
			break;
		}
		case 3:
		{
			cout << "Elija el nombre de un vendedor para asignarle el producto: " << endl;

			controladorUsuarios->listaDeVendedores();
			string nombreVendedor;
			cin >> nombreVendedor;
			string nombreProducto;
			cout << "Indique el nombre del producto" << endl;
			cin >> nombreProducto;
			int codigo;
			cout << "Indique el codigo del producto" << endl;
			cin >> codigo;
			while (controladorVentas->existeCodigo(codigo))
			{
				cout << "El codigo ingresado ya le corresponde a otro producto, por favor ingrese uno distinto: " << endl;
				cin >> codigo;
			}
			cout << "Indique el precio del producto" << endl;
			float precio;
			cin >> precio;
			cout << "Indique la cantidad en stock del producto" << endl;
			int stock;
			cin >> stock;
			cin.ignore();
			string descripcion;
			cout << "Indique la descripcion del producto" << endl;
			getline(cin, descripcion);
			cout << "Indique a cual categoria pertenece su producto: 1-ropa, 2-electrodomesticos, 3-otros" << endl;
			int categoria;
			cin >> categoria;
			while (categoria < 1 || categoria > 3)
			{
				cout << "Categoria invalida, ingrese una de las indicadas: " << endl;
				cin >> categoria;
			}
			ECategoria categoriaEnum = static_cast<ECategoria>(categoria - 1);
			controladorVentas->cargarNuevoProducto(nombreVendedor, codigo, nombreProducto, precio, stock, descripcion, categoriaEnum, false);
			break;
		}
		case 4:
		{
			controladorVentas->listarProductos();
			cout << "Desea consultar algun producto en especifico? Y/N ?" << endl;
			char respuesta1;
			cin >> respuesta1;
			if (respuesta1 == 'Y' || respuesta1 == 'y')
			{
				cout << "Indique el codigo del producto que desea consultar:" << endl;
				int codigo;
				cin >> codigo;
				controladorVentas->consultarProducto(codigo);
			}
			break;
		}
		case 5:
		{
			cout << "Ingrese el nombre de la promocion" << endl;
			cin.ignore();
			string nombrePromo;
			getline(cin, nombrePromo);
			cout << "Ingrese la descripcion de la promocion" << endl;
			string descPromo;
			getline(cin, descPromo);
			cout << "A continuacion ingrese la fecha de vencimiento de su promo:" << endl;
			int anioProm = 0;
			int mesProm = 0;
			int diaProm = 0;
			cout << "Ingrese el anio" << endl;
			cin >> anioProm;
			while (anioProm < anio)
			{
				cout << "Ingrese un anio valido:" << endl;
				cin >> anioProm;
			}
			if (anioProm == anio)
			{ // si el anio es igual, pido mes >=
				cout << "Ingrese el mes" << endl;
				cin >> mesProm;
				while (mesProm > 12 || mesProm < 1 || mesProm < mes)
				{
					cout << "Ingrese un mes valido:" << endl;
					cin >> mesProm;
				}
			}
			else
			{ // si el anio ya es mas grande me sirve cualquier mes
				cout << "Ingrese el mes" << endl;
				cin >> mesProm;
				while (mesProm > 12 || mesProm < 1)
				{
					cout << "Ingrese un mes valido:" << endl;
					cin >> mesProm;
				}
			}
			if (anioProm == anio && mesProm == mes)
			{ // si el anio y el mes sin iguales, pido dia >=
				cout << "Ingrese el dia" << endl;
				cin >> diaProm;
				int cantDiasMesProm = diasMes(mesProm, anioProm);
				while (diaProm > cantDiasMesProm || diaProm < 1 || diaProm < dia)
				{
					cout << "Ingrese un dia valido:" << endl;
					cin >> diaProm;
				}
			}
			else
			{ // el anio o el mes ya es mas grande, me sirve cualquier dia
				cout << "Ingrese el dia" << endl;
				cin >> diaProm;
				int cantDiasMesProm = diasMes(mesProm, anioProm);
				while (diaProm > cantDiasMesProm || diaProm < 1)
				{
					cout << "Ingrese un dia valido:" << endl;
					cin >> diaProm;
				}
			}
			cout << "Ingrese el descuento de la promocion: " << endl;
			float descuento;
			cin >> descuento;
			while (descuento < 0)
			{
				cout << "Ingrese un descuento valido:" << endl;
				cin >> descuento;
			}
			controladorVentas->altaPromocion(nombrePromo, descPromo, DTFecha(diaProm, mesProm, anioProm), descuento);
			string nombreVendedor;
			cin >> nombreVendedor;
			while (!(controladorUsuarios->existeNickname(nombreVendedor) && controladorUsuarios->esVendedor(nombreVendedor)))
			{
				cout << "Ingrese un vendedor valido: " << endl;
			}
			while (!controladorVentas->vendedorTieneProductos(nombreVendedor))
			{
				cout << "En este momento " << nombreVendedor << " no posee ningun producto asociado, vuelva a intentar con otro:" << endl;
				cin >> nombreVendedor;
			}
			controladorVentas->seleccionarVendedor(nombreVendedor);
			while (!controladorVentas->alMenosUnProductoPromo())
			{
				cout << "Ingrese el codigo del producto que desea agregar:" << endl;
				int codigoProd;
				cin >> codigoProd;
				cout << "Ingrese la cantidad minima del producto seleccionado:" << endl;
				int cantProd;
				cin >> cantProd;
				controladorVentas->agregarProductoPromo(codigoProd, cantProd);
			}
			cout << "Desea agregar otro producto a la promocion? Y/N" << endl;
			char masProds;
			cin >> masProds;
			if (masProds == 'Y' || masProds == 'y')
			{
				while (masProds == 'Y' || masProds == 'y')
				{
					cout << "Ingrese el codigo del producto que desea agregar:" << endl;
					int codigoProd;
					cin >> codigoProd;
					cout << "Ingrese la cantidad minima del producto seleccionado:" << endl;
					int cantProd;
					cin >> cantProd;
					controladorVentas->agregarProductoPromo(codigoProd, cantProd);
					cout << "Desea agregar otro producto a la promocion? Y/N" << endl;
					cin >> masProds;
				}
			}
			controladorVentas->ingresarPromocion();
			break;
		}
		case 6:
		{
			controladorVentas->listarPromociones();
			cout << "Desea consultar alguna promocion en especifico? Y/N ?" << endl;
			char respuesta5;
			cin >> respuesta5;
			if (respuesta5 == 'Y' || respuesta5 == 'y')
			{
				cout << "Indique el nombre de la promocion que desea consultar:" << endl;
				string nombrePromocion;
				cin >> nombrePromocion;
				controladorVentas->consultarPromocion(nombrePromocion);
			}
			break;
		}
		case 7:
		{
			cout << "Clientes: " << endl;
			controladorVentas->listarNicknamesClientes();
			cout << "Indique el nickname del cliente: " << endl;
			string nicknameCliente;
			cin.ignore();
			getline(cin, nicknameCliente);
			while (!controladorVentas->seleccionarCliente(nicknameCliente))
			{
				cout << "Nickname inválido. Intente nuevamente ingresando un nickname valido" << endl;
				getline(cin, nicknameCliente);
			}
			string respuesta3 = "Y";
			bool flag = false;
			while (respuesta3 != "N" && respuesta3 != "n")
			{
				cout << "Desea agregar un producto a la compra? Y/N" << endl;
				getline(cin, respuesta3);
				if (respuesta3 == "Y" || respuesta3 == "y")
				{
					flag = true;
					cout << "Indique el codigo y cantidad del producto a agregar en la compra" << endl;
					int codigo;
					cin >> codigo;
					int cantidad;
					cin >> cantidad;
					controladorVentas->agregarProductoCompra(codigo, cantidad);
					cin.ignore();
				}
				else if (respuesta3 == "N" || respuesta3 == "n")
				{
					break;
				}
				else
				{
					cout << "Opción no válida." << endl;
				}
			}
			if (flag)
			{
				controladorVentas->mostrarDetallesCompra();
				cout << "Desea confirmar la compra? Y/N" << endl;
				string respuesta4;
				getline(cin, respuesta4);
				if (respuesta4 == "Y" || respuesta4 == "y")
				{
					controladorVentas->registrarCompra();
					cout << "Compra realizada con éxito." << endl;
				}
				else if (respuesta4 == "N" || respuesta4 == "n")
				{
					cout << "Compra cancelada." << endl;
				}
				else
				{
					cout << "Opción no válida." << endl;
				}
			}
			controladorVentas->liberarMemoriaRealizarCompra();
			break;
		}
		case 8:
		{
			controladorUsuarios->imprimirListaDeUsuarios();
			string NombreUsuario;
			cout << "Indique Nombre del Usuario que desea agregar un comentario: ";
			cin >> NombreUsuario;
			controladorUsuarios->seleccionarUsuario_(NombreUsuario);
			controladorUsuarios->listarProductos();
			int CodigoProducto;
			cout << "Escriba el código del producto al que desea ingresar un comentario: ";
			cin >> CodigoProducto;
			cin.ignore();
			string NombreVendedor;
			cout << "Escriba el nombre del vendedor que publico el producto: ";
			cin >> NombreVendedor;
			controladorUsuarios->seleccionarProducto(CodigoProducto, NombreVendedor);
			cin.ignore(); // Ignorar el carácter de nueva línea residual
			string respuesta;
			cout << "¿Desea dejar un comentario nuevo (C) o responder uno ya existente (R)? ";
			cin >> respuesta;
			if (respuesta == "c" || respuesta == "C"){
				string comentario;
				cin.ignore();
				cout << "Escriba el comentario: ";
				getline(cin, comentario);
				controladorUsuarios->nuevoComentario(comentario, DTFecha(dia, mes, anio));
			}
			else if (respuesta == "r" || respuesta == "R")
			{
				controladorUsuarios->listarComentarios(CodigoProducto);
				int id;
				cout << "Escriba el ID del comentario al que desea responder: ";
				cin >> id;
				string comentador;
				cout << "Escriba el nombre del autor del comentario al que desea responder: ";
				cin >> comentador;
				controladorUsuarios->seleccionarComentario(id, comentador);
				cin.ignore(); // Ignorar el carácter de nueva línea residual
				string comentario;
				cout << "Escriba el comentario: ";
				getline(cin, comentario);
				controladorUsuarios->nuevaRespuesta(comentario, DTFecha(1, 1, 1));
			}
			else{
				cout << "Opcion invalida. \n";
			}
			break;
		}
		case 9:
		{
			controladorUsuarios->imprimirListaDeUsuarios();
			string NombreUsuario;
			cout << "Indique Nombre del Usuario al que desea eliminar un comentario: ";
			cin >> NombreUsuario;
			controladorUsuarios->seleccionarUsuario_(NombreUsuario);
			controladorUsuarios->listarComentariosUsuario(NombreUsuario);
			int IdComentario;
			cout << "Indique ID del comentario que desea eliminar: ";
			cin >> IdComentario;
			Comentario *comentarioAEliminar = controladorUsuarios->buscarComentario(IdComentario, NombreUsuario);
			controladorUsuarios->eliminarComentarioRecursivo(comentarioAEliminar);
			break;
		}
		case 10:
		{
			cout << "Vendedores disponibles:" << endl;
			controladorVentas->listarNicknamesVendedor();
			cout << "Indique el nickname de vendedor:" << endl;
			string nickname;
			cin >> nickname;
			if (controladorVentas->listarProductosPendientes(nickname) == 1)
			{
				cout << "Indique el codigo del producto deseado:" << endl;
				int producto;
				cin >> producto;
				if (controladorVentas->getProductos().find(producto)->first == producto)
				{
					Producto *ptrProducto = controladorVentas->getProductos().find(producto)->second;
					if (controladorVentas->listarComprasAEnviar(ptrProducto) == 1)
					{
						cout << "Indique el cliente a la cual pertenece:" << endl;
						string nickCliente;
						cin>>nickCliente;
						if (controladorUsuarios->existeNickname(nickCliente) && !controladorUsuarios->esVendedor(nickCliente))
						{
							cout << "Seleccione el numero de compra a enviar:" << endl;
							int idCompra;
							cin >> idCompra;
							if (controladorVentas->existeCompraRealizada(nickCliente, idCompra))
							{
								controladorVentas->compraEnviada(idCompra, producto, nickCliente);
								cout << "La compra ha sido modificada correctamente" << endl;
							}
							else {
								cout << "No existe una compra con ID:" << idCompra << endl;
							}
						}
						else {
							cout <<"Cliente inválido." << endl;
						}
					}
					else
					{
						cout << "No hay compras pendientes o la opción es inválida." << endl;
					}
				}
				else
				{
					cout << "\n"
						 << "Opción inválida." << "\n"
						 << endl;
				}
			}
			else if (controladorVentas->getVendedores().find(nickname)->first == nickname)
			{
				cout << "\n"
					 << "No existen compras pendientes de envio del vendedor seleccionado." << "\n"
					 << endl;
			}
			else
			{
				cout << "\n"
					 << "Opción inválida." << "\n"
					 << endl;
			}
			break;
		}
		case 11:
		{
			cout << "Usuarios registrados:" << endl;
			controladorUsuarios->listaDeUsuarios_();
			cout << "¿Cual clase de usuario desea ver?" << endl;
			cout << "1 - Cliente" << endl;
			cout << "2 - Vendedor" << endl;
			int clase;
			cin >> clase;
			cout << "Indique el nickname del usuario:" << endl;
			string nickname;
			cin >> nickname;
			if (controladorUsuarios->existenUsuariosRegistrados())
			{
				switch (clase)
				{
				case 1:
					controladorUsuarios->infoCliente(nickname);
					break;
				case 2:
					controladorVentas->infoVendedor(nickname);
					break;
				default:
					cout << "Su entrada no es válida. Por favor seleccione 1 o 2." << endl;
					break;
				}
			}
			else
			{
				cout << "No existen usuarios registrados. No es posible ver expedientes." << endl;
			}
			break;
		}
		case 12:
		{
			cout << "Usted ha seleccionado suscribirse a notificaciones:" << endl;
			cout << "Desea ver un listado con los posibles suscriptores? Y/N" << endl;
			char resp;
			cin >> resp;
			if (resp == 'Y' || resp == 'y')
			{
				controladorUsuarios->imprimirListaDeClientes();
			}
			cout << "Indique el nombre del nuevo suscriptor" << endl;
			string suscriptorNuevo;
			cin >> suscriptorNuevo;
			controladorUsuarios->imprimirSuscripcionesDisponiblesPara(suscriptorNuevo);
			cout << "Desea registrar una nueva suscripcion entre las disponibles? Y/N" << endl;
			char resp2;
			cin >> resp2;
			while (resp2 != 'n' && resp2 != 'N')
			{
				cout << "Indique a quien desea suscribirse para empezar a recibir sus notificaciones: " << endl;
				string creadorDeContenido;
				cin >> creadorDeContenido;
				if(controladorUsuarios->existeNickname(creadorDeContenido)&&controladorUsuarios->esVendedor(creadorDeContenido)){
					controladorUsuarios->suscribirmeA(creadorDeContenido);
					cout << "Desea ingresar otra suscripcion? Y/N" << endl;
					cin >> resp2;
				}
				else{ 
					cout<<"Nickname invalido, por favor ingrese un nickname que le corresponda a un vendedor: "<<endl;
					cout << "Desea ingresar otra suscripcion? Y/N" << endl;
					cin >> resp2;
				}
			}
			break;
		}
		case 13:
		{
			cout << "Indique el nombre del cliente" << endl;
			string NombreCliente;
			// cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> NombreCliente;
			controladorUsuarios->consultarNotificaciones(NombreCliente);
			break;
		}
		case 14:
		{
			cout << "Indique su nickname: " << endl;
			string nicknameCliente;
			cin>> nicknameCliente;
			if(controladorUsuarios->existeNickname(nicknameCliente) && !controladorUsuarios->esVendedor(nicknameCliente)){
				controladorUsuarios->listarSuscripciones(nicknameCliente);

				string respuesta6 = "Y";
					do{
						cout << "Indique el nickname del vendedor al que desea eliminar la suscripción: " << endl;
						string nicknameVendedor;
						cin>> nicknameVendedor;
						if(controladorUsuarios->existeNickname(nicknameVendedor) && controladorUsuarios->esVendedor(nicknameVendedor)){
							controladorUsuarios->eliminarSuscripciones(nicknameVendedor, nicknameCliente);
						}
						else{
							cout<<"Nickname de vendedor no registrado"<<endl;
						}
						
						if (respuesta6 == "N" || respuesta6 == "n"){
							break;
						}
						cout << "Desea eliminar otra suscripción? Y/N" << endl;
						cin>> respuesta6;
					} while (respuesta6 == "Y" || respuesta6 == "y");
			
			}
			else{
				cout<<"Nickname invalido "<<endl;
			}
			break;
		}
		case 15: {
			//---------------------Casos de prueba tarea 4---------------------//
				
			//Datos básicos de usuarios:
			
			controladorUsuarios->altaVendedor("ana23", "qwer1234", DTFecha(15,5,1988), "212345678001");
			controladorUsuarios->altaVendedor("carlos78", "asdfghj", DTFecha(18,6,1986), "356789012345");
			controladorUsuarios->altaVendedor("diegom", "zxcvbn", DTFecha(28,7,1993), "190123456789");
			controladorUsuarios->altaVendedor("maria01", "5tgb6yhn", DTFecha(25,3,1985), "321098765432");
			controladorUsuarios->altaVendedor("sofia25", "1234asdf", DTFecha(7,12,1983), "445678901234");
			controladorUsuarios->altaCliente("juan87", "1qaz2wsx", DTFecha(20,10,1992),DTDireccion("Av. 18 de Julio", 456), "Melo");
			controladorUsuarios->altaCliente("laura", "3edc4rfv", DTFecha(22,9,1979),DTDireccion("Rondeau", 1617), "Montevideo");
			controladorUsuarios->altaCliente("natalia", "poiuyt", DTFecha(14,4,1982),DTDireccion("Paysandú", 2021), "Salto");
			controladorUsuarios->altaCliente("pablo10", "lkjhgv", DTFecha(30,8,1990),DTDireccion("Av. Rivera ", 1819), "Mercedes");
			controladorUsuarios->altaCliente("roberto", "mnbvcx", DTFecha(12,11,1995),DTDireccion("Av. Brasil", 1011), "Montevideo");
			
			//Datos de prodcutos:

			controladorVentas->cargarNuevoProducto("carlos78", 1, "Camiseta Azul", 1400, 50, "Camiseta de poliéster, color azul", ropa, false);
			controladorVentas->cargarNuevoProducto("ana23", 2, "Televisor LED", 40500, 30, "Televisor LED 55 pulgadas", electrodomesticos, false);
			controladorVentas->cargarNuevoProducto("carlos78", 3, "Chaqueta de Cuero", 699.99, 20, "Chaqueta de cuero, color negro", ropa, false);
			controladorVentas->cargarNuevoProducto("ana23", 4, "Microondas Digital", 1199.99, 15, "Microondas digital, 30L", electrodomesticos, false);
			controladorVentas->cargarNuevoProducto("diegom", 5, "Luz LED", 599.99, 40, "Luz Bluetooth LED", otros, false);
			controladorVentas->cargarNuevoProducto("carlos78", 6, "Pantalones Vaqueros", 60, 25, "Pantalones vaqueros, talla 32", ropa, false);
			controladorVentas->cargarNuevoProducto("diegom", 7, "Auriculares Bluetooth", 199.99, 35, "Auriculares bluetooth para celular", otros, false);
			controladorVentas->cargarNuevoProducto("ana23", 8, "Refrigerador", 15499, 10, "Refrigerador de doble puerta", electrodomesticos, false);
			controladorVentas->cargarNuevoProducto("ana23", 9, "Cafetera", 23000, 50, "Cafetera de goteo programable", electrodomesticos, false);
			controladorVentas->cargarNuevoProducto("carlos78", 10, "Zapatillas Deportivas", 5500, 20, "Zapatillas para correr, talla 42", ropa, false);
			controladorVentas->cargarNuevoProducto("carlos78", 11, "Mochila", 9000, 30, "Mochila de viaje, 40L", otros, false);
			controladorVentas->cargarNuevoProducto("diegom", 12, "Plancha de Ropa", 2534, 25, "Plancha a vapor, 1500W", electrodomesticos, false);
			controladorVentas->cargarNuevoProducto("sofia25", 13, "Gorra", 200, 50, "Gorra para deportes, color rojo", ropa, false);
			controladorVentas->cargarNuevoProducto("diegom", 14, "Tablet", 15000, 15, "Tablet Android de 10 pulgadas", electrodomesticos, false);
			controladorVentas->cargarNuevoProducto("sofia25", 15, "Reloj de Pared", 150.50, 20, "Reloj de pared vintage", otros, false);

			//Datos de promociones:


			controladorVentas->altaPromocion("Casa nueva", "Para que puedas ahorrar en la casa nueva", DTFecha(25, 10, 2024), 30);
			controladorVentas->seleccionarVendedor("ana23");
			controladorVentas->agregarProductoPromo(2, 1);
			controladorVentas->agregarProductoPromo(4, 1);
			controladorVentas->agregarProductoPromo(8, 1);
			controladorVentas->ingresarPromocion();

			controladorVentas->altaPromocion("Fiesta", "Para que no te quedes sin ropa para las fiestas", DTFecha(26, 10, 2024), 20);
			controladorVentas->seleccionarVendedor("carlos78");
			controladorVentas->agregarProductoPromo(6, 1);
			controladorVentas->agregarProductoPromo(3, 2);
			controladorVentas->ingresarPromocion();

			controladorVentas->altaPromocion("Domotica", "Para modernizar tu casa", DTFecha(26, 10, 2024), 10);
			controladorVentas->seleccionarVendedor("diegom");
			controladorVentas->agregarProductoPromo(5, 2);
			controladorVentas->ingresarPromocion();

			controladorVentas->altaPromocion("Liquidacion", "Hasta agotar stock", DTFecha(26, 3, 2024), 10);
			controladorVentas->seleccionarVendedor("diegom");
			controladorVentas->agregarProductoPromo(14, 1);
			controladorVentas->ingresarPromocion();

			//Datos compras:

			controladorVentas->seleccionarCliente("juan87");
			controladorVentas->agregarProductoCompra(2, 2);
			controladorVentas->agregarProductoCompra(4, 1);
			controladorVentas->agregarProductoCompra(8, 1);
			controladorVentas->mostrarDetallesCompra();
			controladorVentas->registrarCompra();
			controladorVentas->compraEnviada(1,2,"juan87");
			controladorVentas->liberarMemoriaRealizarCompra();

			controladorVentas->seleccionarCliente("juan87");
			controladorVentas->agregarProductoCompra(5, 1);
			controladorVentas->mostrarDetallesCompra();
			controladorVentas->registrarCompra();
			controladorVentas->compraEnviada(2,5,"juan87");
			controladorVentas->liberarMemoriaRealizarCompra();

			controladorVentas->seleccionarCliente("laura");
			controladorVentas->agregarProductoCompra(14, 10);
			controladorVentas->mostrarDetallesCompra();
			controladorVentas->registrarCompra();
			controladorVentas->compraEnviada(3,14,"laura");
			controladorVentas->liberarMemoriaRealizarCompra();

			controladorVentas->seleccionarCliente("natalia");
			controladorVentas->agregarProductoCompra(11, 1);
			controladorVentas->agregarProductoCompra(12, 1);
			controladorVentas->agregarProductoCompra(13, 1);
			controladorVentas->mostrarDetallesCompra();
			controladorVentas->registrarCompra();
			controladorVentas->compraEnviada(4,11,"natalia");
			controladorVentas->compraEnviada(4,12,"natalia");
			controladorVentas->compraEnviada(4,13,"natalia");
			controladorVentas->liberarMemoriaRealizarCompra();

			controladorVentas->seleccionarCliente("juan87");
			controladorVentas->agregarProductoCompra(3, 2);
			controladorVentas->agregarProductoCompra(6, 1);
			controladorVentas->mostrarDetallesCompra();
			controladorVentas->registrarCompra();
			controladorVentas->compraEnviada(5,6,"juan87");
			controladorVentas->liberarMemoriaRealizarCompra();

			controladorVentas->seleccionarCliente("laura");
			controladorVentas->agregarProductoCompra(1, 2);
			controladorVentas->mostrarDetallesCompra();
			controladorVentas->registrarCompra();
			controladorVentas->liberarMemoriaRealizarCompra();

			controladorVentas->seleccionarCliente("natalia");
			controladorVentas->agregarProductoCompra(1, 3);
			controladorVentas->mostrarDetallesCompra();
			controladorVentas->registrarCompra();
			controladorVentas->compraEnviada(7,1,"natalia");
			controladorVentas->liberarMemoriaRealizarCompra();

			controladorVentas->seleccionarCliente("pablo10");
			controladorVentas->agregarProductoCompra(1, 4);
			controladorVentas->mostrarDetallesCompra();
			controladorVentas->registrarCompra();
			controladorVentas->liberarMemoriaRealizarCompra();

			controladorVentas->seleccionarCliente("roberto");
			controladorVentas->agregarProductoCompra(1, 5);
			controladorVentas->mostrarDetallesCompra();
			controladorVentas->registrarCompra();
			controladorVentas->liberarMemoriaRealizarCompra();	

			

			//Datos de Comentarios:
				
			//=========================CASO PRODUCTO 1 CARLOS78===================================================
			
			//CM1
			controladorUsuarios->seleccionarUsuario_("juan87");
			controladorUsuarios->seleccionarProducto(1, "carlos78");
			controladorUsuarios->nuevoComentario("¿La camiseta azul esta disponible en talla M?", DTFecha(1, 6, 2024));
			//CM2
			controladorUsuarios->seleccionarUsuario_("carlos78");
			controladorUsuarios->seleccionarProducto(1, "carlos78");
			controladorUsuarios->seleccionarComentario(0, "juan87");
			controladorUsuarios->nuevaRespuesta("Si, tenemos la camiseta azul en talla M.", DTFecha(1, 6, 2024));
			//CM3
			controladorUsuarios->seleccionarUsuario_("laura");
			controladorUsuarios->seleccionarProducto(1, "carlos78");
			controladorUsuarios->seleccionarComentario(1, "carlos78");
			controladorUsuarios->nuevaRespuesta("¿Es de buen material? Me preocupa la durabilidad.", DTFecha(1, 6, 2024));
			//CM4
			controladorUsuarios->seleccionarUsuario_("juan87");
			controladorUsuarios->seleccionarProducto(1, "carlos78");
			controladorUsuarios->seleccionarComentario(2, "laura");
			controladorUsuarios->nuevaRespuesta("He comprado antes y la calidad es buena.", DTFecha(1, 6, 2024));
			//CM5
			controladorUsuarios->seleccionarUsuario_("natalia");
			controladorUsuarios->seleccionarProducto(1, "carlos78");
			controladorUsuarios->nuevoComentario("¿Como es el ajuste? ¿Es ajustada o holgada?", DTFecha(02,06,2024));
			
			// ======================================================================================================
			
			//==============================CASO PRODUCTO 2 ANA23====================================================
			
			//CM6
			controladorUsuarios->seleccionarUsuario_("laura");
			controladorUsuarios->seleccionarProducto(2, "ana23");
			controladorUsuarios->nuevoComentario("¿Cual es la resolucion del Televisor LED?", DTFecha(02,06,2024));
			//CM7
			controladorUsuarios->seleccionarUsuario_("ana23");
			controladorUsuarios->seleccionarProducto(2, "ana23");
			controladorUsuarios->seleccionarComentario(5, "laura");
			controladorUsuarios->nuevaRespuesta("El televisor LED tiene una resolucion de 4K UHD.", DTFecha(02, 06, 2024));
			//CM8
			controladorUsuarios->seleccionarUsuario_("pablo10");
			controladorUsuarios->seleccionarProducto(2, "ana23");
			controladorUsuarios->nuevoComentario("¿Tiene soporte para HDR10?", DTFecha(03, 06, 2024));
			//CM9
			controladorUsuarios->seleccionarUsuario_("ana23");
			controladorUsuarios->seleccionarProducto(2, "ana23");
			controladorUsuarios->seleccionarComentario(7, "pablo10");
			controladorUsuarios->nuevaRespuesta("Si, soporta HDR10.", DTFecha(03, 06, 2024));
			
			//========================================================================================================
			
			//=============================CASO PRODUCTO 3 CARLOS78===================================================
			
			//CM10
			controladorUsuarios->seleccionarUsuario_("natalia");
			controladorUsuarios->seleccionarProducto(3, "carlos78");
			controladorUsuarios->nuevoComentario("¿La chaqueta de cuero es resistente al agua?", DTFecha(03, 06, 2024));
			//CM11
			controladorUsuarios->seleccionarUsuario_("carlos78");
			controladorUsuarios->seleccionarProducto(3, "carlos78");
			controladorUsuarios->seleccionarComentario(9, "natalia");
			controladorUsuarios->nuevaRespuesta("No, la chaqueta de cuero no es resistente al agua", DTFecha(03, 06, 2024));
			//CM12
			controladorUsuarios->seleccionarUsuario_("laura");
			controladorUsuarios->seleccionarProducto(3, "carlos78");
			controladorUsuarios->seleccionarComentario(9, "natalia");
			controladorUsuarios->nuevaRespuesta("¿Viene en otros colores?", DTFecha(04, 06, 2024));
			//CM13
			controladorUsuarios->seleccionarUsuario_("carlos78");
			controladorUsuarios->seleccionarProducto(3, "carlos78");
			controladorUsuarios->seleccionarComentario(11, "laura");
			controladorUsuarios->nuevaRespuesta("Si, tambien esta disponible en marron.", DTFecha(04, 06, 2024));
			//CM14
			controladorUsuarios->seleccionarUsuario_("roberto");
			controladorUsuarios->seleccionarProducto(3, "carlos78");
			controladorUsuarios->seleccionarComentario(9, "natalia");
			controladorUsuarios->nuevaRespuesta("¿Es adecuada para climas frios?", DTFecha(04, 06, 2024));
			
			//====================================================================================================
			
			//==================================CASO PRODUCTO 4 ANA23=============================================
			
			//CM15
			controladorUsuarios->seleccionarUsuario_("pablo10");
			controladorUsuarios->seleccionarProducto(4, "ana23");
			controladorUsuarios->nuevoComentario("¿El microondas digital tiene funcion de descongelacion rapida?", DTFecha(04, 06, 2024));
			//CM16
			controladorUsuarios->seleccionarUsuario_("ana23");
			controladorUsuarios->seleccionarProducto(4, "ana23");
			controladorUsuarios->seleccionarComentario(14, "pablo10");
			controladorUsuarios->nuevaRespuesta("Si, el microondas digital incluye una funcion de descongelacion rapida.", DTFecha(04, 06, 2024));
			//CM17
			controladorUsuarios->seleccionarUsuario_("natalia");
			controladorUsuarios->seleccionarProducto(4, "ana23");
			controladorUsuarios->seleccionarComentario(14, "pablo10");
			controladorUsuarios->nuevaRespuesta("¿Cuantos niveles de potencia tiene? ", DTFecha(05, 06, 2024));
			//CM18
			controladorUsuarios->seleccionarUsuario_("ana23");
			controladorUsuarios->seleccionarProducto(4, "ana23");
			controladorUsuarios->seleccionarComentario(16, "natalia");
			controladorUsuarios->nuevaRespuesta("Tiene 10 niveles de potencia.", DTFecha(05, 06, 2024));
			//CM19
			controladorUsuarios->seleccionarUsuario_("roberto");
			controladorUsuarios->seleccionarProducto(4, "ana23");
			controladorUsuarios->seleccionarComentario(14, "pablo10");
			controladorUsuarios->nuevaRespuesta("¿Es facil de limpiar? ", DTFecha(05, 06, 2024));
			
			//==========================================================================================
			
			//===========================CASO PRODUCTO 5 DIEGOM=========================================
			
			//CM20
			controladorUsuarios->seleccionarUsuario_("roberto");
			controladorUsuarios->seleccionarProducto(5, "diegom");
			controladorUsuarios->nuevoComentario("¿La luz LED se puede controlar con una aplicacion movil?", DTFecha(05, 06, 2024));
			//CM21
			controladorUsuarios->seleccionarUsuario_("diegom");
			controladorUsuarios->seleccionarProducto(5, "diegom");
			controladorUsuarios->seleccionarComentario(19, "roberto");
			controladorUsuarios->nuevaRespuesta("Si, la luz LED se puede controlar a traves de una aplicacion movil", DTFecha(5, 6, 2024));
			//CM22
			controladorUsuarios->seleccionarUsuario_("pablo10");
			controladorUsuarios->seleccionarProducto(5, "diegom");
			controladorUsuarios->seleccionarComentario(19, "roberto");
			controladorUsuarios->nuevaRespuesta("¿Es compatible con Alexa o Google Home?", DTFecha(6, 6, 2024));
			//CM23
			controladorUsuarios->seleccionarUsuario_("diegom");
			controladorUsuarios->seleccionarProducto(5, "diegom");
			controladorUsuarios->seleccionarComentario(21, "pablo10");
			controladorUsuarios->nuevaRespuesta("Si, es compatible con ambos.", DTFecha(6, 6, 2024));
			//CM24
			controladorUsuarios->seleccionarUsuario_("natalia");
			controladorUsuarios->seleccionarProducto(5, "diegom");
			controladorUsuarios->seleccionarComentario(19, "roberto");
			controladorUsuarios->nuevaRespuesta("¿Cuanto dura la bateria?", DTFecha(6, 6, 2024));
			//CM25
			controladorUsuarios->seleccionarUsuario_("pablo10");
			controladorUsuarios->seleccionarProducto(5, "diegom");
			controladorUsuarios->seleccionarComentario(19, "roberto");
			controladorUsuarios->nuevaRespuesta("¿La aplicacion movil es facil de usar?", DTFecha(7, 6, 2024));
			break;
		}
		case 0:
			cout << "Saliendo del programa...\n";
			break;
		default:
			cout << "Opción inválida. Por favor, ingrese una opción válida.\n";
			break;
		}
	} while (opcion != 0);

	// ** SE LIBERA LA MEMORIA ** //

	return 0;
}