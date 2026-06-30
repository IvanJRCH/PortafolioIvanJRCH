/* Ivan Jesus Rojas Chaparro */
#include <windows.h>
#include <shellapi.h>
#define LINKDING 1
#define GITHUB 2
#define GITLAB 3
#define YOUTUBE 4

/*  Esta función es invocada por la función DispatchMessage()  */
LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT mensaje, WPARAM wParam, LPARAM lParam)
{
    switch (mensaje)                  /* manipulador de mensaje */
    { 
        case WM_COMMAND:
        {
          switch(wParam) {
          case LINKDING:
          {
            ShellExecuteA(NULL,"open","https://www.linkedin.com/in/ivan-j-hj-rojas-ch-26502431a",NULL,NULL,SW_SHOWNORMAL);
          }
          break;
          case GITHUB:
          {
             ShellExecuteA(NULL,"open","https://github.com/IvanJRCH",NULL,NULL,SW_SHOWNORMAL);
          }
          break;
          case GITLAB:
          {
             ShellExecuteA(NULL,"open","https://gitlab.com/IvanJRCH",NULL,NULL,SW_SHOWNORMAL);
          }
          break;
          case YOUTUBE:
          {
             ShellExecuteA(NULL,"open","https://www.youtube.com/@ivanrojas1785",NULL,NULL,SW_SHOWNORMAL);
          }
          break;
          }
        }
        break;
        case WM_DESTROY:
            PostQuitMessage (0);       /* Envía el mensaje WM_QUIT a la cola de mensajes */
            break;
        default:                      /* Mensajes que no queremos manejar */
            return DefWindowProc (hwnd, mensaje, wParam, lParam);
    }

    return 0;
}

int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)
{
    HWND hwnd;               /* Manipulador de ventana */
    MSG mensaje;             /* Mensajes recibidos por la aplicación */
    WNDCLASSEX wincl;        /* Estructura de datos para la clase de ventana */

    /* Estructura de la ventana */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = "IvanJRCHPortafolio";
    wincl.lpfnWndProc = WindowProcedure;      /* Esta función es invocada por Windows */
    wincl.style = CS_DBLCLKS;                 /* Captura los doble-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Usar icono y puntero por defector */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* Sin menú */
    wincl.cbClsExtra = 0;                      /* Sin información adicional para la */
    wincl.cbWndExtra = 0;                      /* clase o la ventana */
    /* Usar el color de fondo por defecto para la ventana */
    wincl.hbrBackground = GetSysColorBrush(COLOR_WINDOW);

    /* Registrar la clase de ventana, si falla, salir del programa */
    if(!RegisterClassEx(&wincl)) return 0;

    /* La clase está registrada, crear la ventana */
    hwnd = CreateWindowEx(
           0,                   /* Posibilidades de variación */
           "IvanJRCHPortafolio",     /* Nombre de la clase */
           "IvanJRCH Portafolio",       /* Texto del título */
           WS_SYSMENU | WS_CAPTION | WS_MINIMIZEBOX | WS_VISIBLE, /* Tipo por defecto */
           CW_USEDEFAULT,       /* Windows decide la posición */
           CW_USEDEFAULT,       /* donde se coloca la ventana */
           350,                 /* Ancho */
           250,                 /* Alto en pixels */
           HWND_DESKTOP,        /* La ventana es hija del escritorio */
           NULL,                /* Sin menú */
           hThisInstance,       /* Manipulador de instancia */
           NULL                 /* No hay datos de creación de ventana */
    );

    /* Mostrar la ventana */
    ShowWindow(hwnd, SW_SHOWDEFAULT);
    
    CreateWindowEx(0,"static","Hola. Bienvenido a mi menu de accesos directos a mis portafolios.",WS_CHILD|WS_VISIBLE,0,0,340,50,hwnd,(HMENU)-1,hThisInstance,NULL);
    
    HWND boton1 = CreateWindowEx(0,"button","Linkding",WS_CHILD|WS_VISIBLE,10,60,120,30,hwnd,(HMENU)LINKDING,hThisInstance,NULL);
  
    HWND boton2 = CreateWindowEx(0,"button","Github",WS_CHILD|WS_VISIBLE,10,60 + 30 + 5,120,30,hwnd,(HMENU)GITHUB,hThisInstance,NULL);
    
    HWND boton3 = CreateWindowEx(0,"button","Gitlab",WS_CHILD|WS_VISIBLE,10,60 + 30*2 + 5*2,120,30,hwnd,(HMENU)GITLAB,hThisInstance,NULL);
    
    HWND boton4 = CreateWindowEx(0,"button","Youtube",WS_CHILD|WS_VISIBLE,10,60 + 30*3 + 5*3,120,30,hwnd,(HMENU)YOUTUBE,hThisInstance,NULL);
    
    /* Bucle de mensajes, se ejecuta hasta que haya error o GetMessage devuelva FALSE */
    while(TRUE == GetMessage(&mensaje, NULL, 0, 0))
    {
        /* Traducir mensajes de teclas virtuales a mensajes de caracteres */
        TranslateMessage(&mensaje);
        /* Enviar mensaje al procedimiento de ventana */
        DispatchMessage(&mensaje);
    }

    /* Salir con valor de retorno */
    return mensaje.wParam;
}

