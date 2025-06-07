public class LaberintoVoraz {

    static int[][] laberinto = {
        {5, 3, 2},
        {1,10, 1},
        {4, 2, 1}
    };

    static int oroTotal = 0;
    static String camino = "";

    public static void main(String[] args) {
        System.out.println("Inicio del recorrido del laberinto:");
        buscarOro(0, 0);
        System.out.println("\nRecorrido finalizado.");
        System.out.println("Oro total recogido: " + oroTotal);
        System.out.println("Camino seguido: " + camino + "FIN");
    }

    public static void buscarOro(int fila, int columna) {
        while (true) {
            int oroActual = laberinto[fila][columna];
            oroTotal += oroActual;
            camino += "(" + fila + "," + columna + ") -> ";

            System.out.println("Estás en la celda (" + fila + "," + columna + ") con " + oroActual + " de oro.");
            System.out.println("Oro acumulado hasta ahora: " + oroTotal);

            boolean puedeMoverDerecha = (columna + 1) < laberinto[0].length;
            boolean puedeMoverAbajo = (fila + 1) < laberinto.length;

            if (!puedeMoverDerecha && !puedeMoverAbajo) {
                System.out.println("No puedes moverte más, llegaste al final.");
                break; // Llegamos al final del laberinto
            }

            int oroDerecha = puedeMoverDerecha ? laberinto[fila][columna + 1] : -1;
            int oroAbajo = puedeMoverAbajo ? laberinto[fila + 1][columna] : -1;

            System.out.print("Opciones disponibles: ");
            if (puedeMoverDerecha) System.out.print("Derecha (" + oroDerecha + " de oro) ");
            if (puedeMoverAbajo) System.out.print("Abajo (" + oroAbajo + " de oro) ");
            System.out.println();

            // Decidir a dónde moverse
            if (oroAbajo > oroDerecha) {
                System.out.println("Elijo moverme abajo porque " + oroAbajo + " > " + oroDerecha);
                fila++;
            } else {
                System.out.println("Elijo moverme a la derecha porque " + oroDerecha + " >= " + oroAbajo);
                columna++;
            }

            System.out.println("----------------------------");
        }
    }
}

