
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}Employee;

/** \brief Inicializa el campo "isEmpty" del array de empleados en '1'
 *
 * \param lista de Empleados
 * \param length de la lista de empleados
 * \return int 0 si salio ok / -1 si no se pudo inicializar
 *
 */
int initEmployees(Employee* list, int len);

/** \brief Busca un lugar sin cargar en el array de empleados y devuelve dicho indice
 *
 * \param lista de Empleados
 * \param length de la lista de empleados
 * \return int 0 si salio ok / -1 si no se encontro
 *
 */
int findFreeSpace(Employee* list,int len);

/** \brief Hace el alta de un empleado
 *
 * \param id a asignar al nuevo empleado
 * \return 0 si ok / -1 si no hay lugar
 *
 */
int addEmployee(Employee* list, int len, int id);

 /** \brief muestra un empleado
  *
  * \param el empleado a mostrar
  * \return void
  *
  */
void showEmployee(Employee x);

/** \brief busca un empleado por "id" en el array
 *
 * \param el id a ser encontrado
 * \param lista de Empleados
 * \param length de la lista de empleados
 * \return indice del empleado a buscar si ok / -1 si no lo encontro
 *
 */
int searchEmployeeById(int id, Employee* e,int len);

/** \brief modifica algun campo de un empleado
 *
 * \param lista de Empleados
 * \param length de la lista de empleados
 * \return 0 si modifico / -1 si no modifico
 *
 */
int modifyEmployee(Employee* e,int len);

/** \brief Da la baja logica a un empleado (isEmpty = 1)
 *
 * \param lista de Empleados
 * \param length de la lista de empleados
 * \return 0 si elimino / -1 si no
 *
 */
int deleteEmployee(Employee* e,int len);

/** \brief ordena los empleados por apellido o sector
 *
 * \param lista de Empleados
 * \param length de la lista de empleados
 * \param criterio de orden ascendente o descendente
 * \return 0 si ordeno y mostro / -1 si no
 *
 */
int sortEmployee(Employee* e, int tam,int orden);

/** \brief  muestra un menu de informes y ejecuta sus respectivas funciones
 *
 * \param lista de Empleados
 * \param length de la lista de empleados
 * \return 0 si ok / -1 si no ok
 *
 */
int listEmployee(Employee* e,int tam);

/** \brief muestra los salarios promedio, el total de salarios y cantidad de empleados arriba del promedio
 *
 * \param lista de Empleados
 * \param length de la lista de empleados
 * \return void
 *
 */
void showSalaries(Employee* e,int len);
//************************
