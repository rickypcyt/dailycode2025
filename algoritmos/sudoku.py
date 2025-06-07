# Esta función verifica si es válido colocar un número en una celda del Sudoku.
def es_valido(tablero, fila, col, num):
    # Verificamos si el número ya existe en la fila actual
    for i in range(9):
        if tablero[fila][i] == num:
            return False  # Ya hay un número igual en la fila

    # Verificamos si el número ya existe en la columna actual
    for i in range(9):
        if tablero[i][col] == num:
            return False  # Ya hay un número igual en la columna

    # Verificamos si el número ya existe en el subcuadro 3x3 al que pertenece la celda
    inicio_fila = (fila // 3) * 3  # Fila de inicio del subcuadro
    inicio_col = (col // 3) * 3  # Columna de inicio del subcuadro
    for i in range(3):
        for j in range(3):
            if tablero[inicio_fila + i][inicio_col + j] == num:
                return False  # Ya hay un número igual en el subcuadro 3x3

    return True  # Si pasa todas las pruebas, el número es válido


# Esta es la función principal que intenta resolver el Sudoku usando backtracking
def resolver_sudoku(tablero):
    # Recorremos cada celda del tablero
    for fila in range(9):
        for col in range(9):
            # Si encontramos una celda vacía (representada con 0)
            if tablero[fila][col] == 0:
                # Intentamos colocar un número del 1 al 9
                for num in range(1, 10):
                    # Verificamos si es válido colocar ese número aquí
                    if es_valido(tablero, fila, col, num):
                        # ✅ Colocamos el número en la celda
                        tablero[fila][col] = num
                        print(f"Coloco {num} en posición ({fila}, {col})")

                        # 🧠 Llamamos recursivamente para intentar llenar el resto del tablero
                        if resolver_sudoku(tablero):
                            return True  # Si resolvió bien, no hacemos más cambios

                        # 🚫 Si más adelante no se puede resolver, hacemos backtracking:
                        # quitamos el número y probamos otro
                        tablero[fila][col] = 0
                        print(f"Retrocedo: elimino {num} de posición ({fila}, {col})")

                # Si ningún número del 1 al 9 es válido en esta celda, hay que retroceder más
                return False

    # Si no quedan celdas vacías, el tablero está resuelto
    return True

