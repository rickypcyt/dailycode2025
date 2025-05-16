def fib_memo(n, memo=None, depth=0):
    if memo is None:
        memo = {}
    indent = "  " * depth  # Para mostrar profundidad
    
    if n in memo:
        print(f"{indent}fib({n}) ya calculado: {memo[n]}")
        return memo[n]
    
    if n <= 1:
        print(f"{indent}fib({n}) caso base: {n}")
        return n
    
    print(f"{indent}Calculando fib({n}) llamando fib({n-1}) y fib({n-2})...")
    
    # Calcular recursivamente
    val1 = fib_memo(n-1, memo, depth+1)
    val2 = fib_memo(n-2, memo, depth+1)
    
    memo[n] = val1 + val2  # Guardar resultado
    print(f"{indent}fib({n}) = fib({n-1}) + fib({n-2}) = {val1} + {val2} = {memo[n]} (guardado en memo)")
    
    return memo[n]

print("=== Memoización ===")
resultado_memo = fib_memo(6)
print(f"\nResultado Memoización: {resultado_memo}")

def fib_tabu(n):
    if n <= 1:
        print(f"fib({n}) caso base: {n}")
        return n
    
    dp = [0] * (n+1)
    dp[0] = 0
    dp[1] = 1
    
    print(f"Tabla inicial (casos base): {dp}")
    
    for i in range(2, n+1):
        dp[i] = dp[i-1] + dp[i-2]
        print(f"dp[{i}] = dp[{i-1}] + dp[{i-2}] => {dp[i-1]} + {dp[i-2]} = {dp[i]}")
    
    print(f"Tabla completa final: {dp}")
    return dp[n]

print("\n=== Tabulación ===")
resultado_tabu = fib_tabu(6)
print(f"\nResultado Tabulación: {resultado_tabu}")

