import numpy as np
import sympy as sp
import control as ctrl

# 定义符号变量
t = sp.symbols('t')
x = sp.Function('x')(t)
theta = sp.Function('theta')(t)
T, R, Iw, mw, L, mp, g, Ip = sp.symbols('T R Iw mw L mp g Ip')
f1, f2, d_theta, d_x, theta0, x0 = sp.symbols('f1 f2 d_theta d_x theta0 x0')

# 设置物理参数
lw = 0.5 / 2      # 摆杆质心高度
lb = 0.5 + 0.09   # 机体质心高度
R1 = 0.1          # 驱动轮半径
mw1 = 1.18        # 驱动轮质量
mb = 5.0 / 2          # 机体质量
ml = 0.8          # 摆杆质量

mp1 = mb + ml     # 总质量
L1 = (lb * mb + lw * ml) / mp1  # 总重心到轮轴距离
Iw1 = mw1 * R1**2  # 驱动轮转动惯量
Ip1 = mb * (lb - L1)**2 + ml * (L1 - lw)**2  # 摆杆转动惯量
g_val = 9.8       # 重力加速度

# 定义动力学方程
N = mp * sp.diff(x + L * sp.sin(theta), t, 2)
P = mp * g + mp * sp.diff(L * sp.cos(theta), t, 2)

# 构建运动方程
eqn1 = sp.Eq(sp.diff(x, t, 2), (T - N * R) / (Iw / R + mw * R))
eqn2 = sp.Eq(Ip * sp.diff(theta, t, 2), P * L * sp.sin(theta) - N * L * sp.cos(theta) - T)

# 替换高阶导数
ddt = {sp.diff(theta, t, 2): f1,
       sp.diff(x, t, 2): f2,
       sp.diff(theta, t): d_theta,
       sp.diff(x, t): d_x,
       theta: theta0,
       x: x0}

eqn10 = eqn1.subs(ddt).simplify()
eqn20 = eqn2.subs(ddt).simplify()

# 求解f1和f2
solutions = sp.solve([eqn10, eqn20], (f1, f2))
f1_expr = solutions[f1].simplify()
f2_expr = solutions[f2].simplify()

# 定义状态向量
states = [theta0, d_theta, x0, d_x]

# 计算雅可比矩阵（A和B）
A_symbolic = sp.Matrix([
    [sp.diff(d_theta, s) for s in states],
    [sp.diff(f1_expr, s) for s in states],
    [sp.diff(d_x, s) for s in states],
    [sp.diff(f2_expr, s) for s in states]
])

B_symbolic = sp.Matrix([
    sp.diff(d_theta, T),
    sp.diff(f1_expr, T),
    sp.diff(d_x, T),
    sp.diff(f2_expr, T)
])

# 在平衡点进行数值替换
balance_point = {theta0: 0, d_theta: 0, d_x: 0, T: 0}
A_balanced = A_symbolic.subs(balance_point)
B_balanced = B_symbolic.subs(balance_point)

# 代入物理参数
param_subs = {
    R: R1,
    L: L1,
    mw: mw1,
    mp: mp1,
    Iw: Iw1,
    Ip: Ip1,
    g: g_val
}

A_num = np.array(A_balanced.subs(param_subs)).astype(np.float64)
B_num = np.array(B_balanced.subs(param_subs)).astype(np.float64)

# 设计LQR控制器
Q = np.diag([1000, 100, 1500, 100])  # 状态权重
R_val = 50.0                          # 控制权重

# 使用control库计算LQR增益
K, S, E = ctrl.lqr(A_num, B_num, Q, R_val)

print("\nLQR增益矩阵 K:")
print(K)
