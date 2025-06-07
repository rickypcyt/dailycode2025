from graphviz import Digraph

# Datos de ejemplo
capacidad = 5
objetos = [(2, 3), (3, 4)]  # (peso, valor) y son dos objs

dot = Digraph()
dot.attr(rankdir='TB')

nodo_id = 0
mejor_valor = 0

def nombre_nodo():
    global nodo_id
    nodo = f'N{nodo_id}'
    nodo_id += 1
    return nodo

def construir_arbol(i, peso, valor, decisiones, padre_id=None):
    global mejor_valor

    if peso > capacidad:
        # ✂️ Poda por exceso de peso
        return

    nombre = nombre_nodo()
    etiqueta = f'obj{i}\n(p={peso}, v={valor})\n{decisiones}'
    dot.node(nombre, etiqueta)

    if padre_id is not None:
        dot.edge(padre_id, nombre)

    if i == len(objetos):
        # Hoja: actualiza mejor valor
        if valor > mejor_valor:
            mejor_valor = valor
        return

    # Caso 1: no incluir objeto i
    construir_arbol(i + 1, peso, valor, decisiones + ['❌'], nombre)

    # Caso 2: incluir objeto i
    nuevo_peso = peso + objetos[i][0]
    nuevo_valor = valor + objetos[i][1]
    construir_arbol(i + 1, nuevo_peso, nuevo_valor, decisiones + ['✅'], nombre)

# Inicia desde la raíz (sin nada)
construir_arbol(0, 0, 0, [])

dot.render('mochila_backtracking', format='png', view=True)

print(f"Mejor valor encontrado: {mejor_valor}")

