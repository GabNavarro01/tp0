#include "client.h"

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/

	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_config* config;

	/* ---------------- LOGGING ---------------- */

	logger = iniciar_logger();
	//log_info(logger, "Hola soy un log!")

	/* ---------------- ARCHIVOS DE CONFIGURACION ---------------- */

	config = iniciar_config();

	valor = config_get_string_value(config, "CLAVE");
	ip = config_get_string_value(config, "IP");
	puerto = config_get_string_value(config, "PUERTO");

	log_info(logger, "El valor de la clave de la congis es %s", valor);
	log_info(logger, "El valor ip de la congis es %s", ip);
	log_info(logger, "El valor del puerto de la congis es %s" , puerto);

	/* ---------------- LEER DE CONSOLA ---------------- */

	leer_consola(logger);


	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// ADVERTENCIA: Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo para poder conectarnos a él

	// Creamos una conexión hacia el servidor
	conexion = crear_conexion(ip, puerto);

	// Enviamos al servidor el valor de CLAVE como mensaje

	// Armamos y enviamos el paquete
	paquete(conexion);

	terminar_programa(conexion, logger, config);

	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// Proximamente
}

t_log* iniciar_logger(void)
{
	t_log* nuevo_logger = log_create("tp0.log" , "LOGGER_TP0", true, LOG_LEVEL_INFO);
	if (nuevo_logger ==  NULL){
		perror("Error en el LOGGER");
		exit(EXIT_FAILURE);
	}
	return nuevo_logger;
}

t_config* iniciar_config(void)
{
	t_config* nuevo_config = config_create("cliente.config");
	if(nuevo_config == NULL){
		perror("Hubo un error en las CONFIG");
		exit(EXIT_FAILURE);
	}
	return nuevo_config;

}

void leer_consola(t_log* logger)
{
	char* leido;

	// La primera te la dejo de yapa
	// leido = readline("> ");

	// El resto, las vamos leyendo y logueando hasta recibir un string vacío
    while (1) {
        leido = readline(">");
		if (strcmp(leido,"") == 0) {
			break;
		}
        log_info(logger, ">> %s", leido);
        free(leido);
    }
	// ¡No te olvides de liberar las lineas antes de regresar!
}

void paquete(int conexion)
{
	// Ahora toca lo divertido!
	char* leido;
	t_paquete* paquete;

	// Leemos y esta vez agregamos las lineas al paquete


	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!
	
}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	/* Y por ultimo, hay que liberar lo que utilizamos (conexion, log y config) 
	  con las funciones de las commons y del TP mencionadas en el enunciado */
	log_destroy(logger);
	config_destroy(config);
}
