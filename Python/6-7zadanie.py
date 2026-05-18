import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns


data = {
    'Month Number': [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12],
    'face Cream': [2500, 2600, 2700, 2800, 2900, 3000, 3100, 3200, 3300, 3400, 3500, 3600],
    'Face wash': [1500, 1550, 1600, 1650, 1700, 1750, 1800, 1850, 1900, 1950, 2000, 2050],
    'Tooth paste': [3000, 3100, 3200, 3300, 3400, 3500, 3600, 3700, 3800, 3900, 4000, 4100],
    'Bathing soap': [4000, 4200, 4400, 4600, 4800, 5000, 5200, 5400, 5600, 5800, 6000, 6200],
    'Shampoo': [2000, 2100, 2200, 2300, 2400, 2500, 2600, 2700, 2800, 2900, 3000, 3100],
    'Moisturizer': [1800, 1900, 2000, 2100, 2200, 2300, 2400, 2500, 2600, 2700, 2800, 2900]
}
df = pd.DataFrame(data)





plt.figure(figsize=(12, 7))
sns.set_style("whitegrid")


colors = ['blue', 'cyan', 'red', 'black', 'green', 'yellow']
products = ['face Cream', 'Face wash', 'Tooth paste', 'Bathing soap', 'Shampoo', 'Moisturizer']

plt.stackplot(df['Month Number'],
              [df[product] for product in products],
              labels=products,
              colors=colors,
              alpha=0.85)

plt.xlabel('Month Number', fontsize=12)
plt.ylabel('Sales units in Number', fontsize=12)
plt.title('All Product Sales Data - Stacked Area Chart', fontsize=14, fontweight='bold')
plt.legend(loc='upper left', bbox_to_anchor=(1, 1))
plt.tight_layout()
plt.show()




import numpy as np
import matplotlib.pyplot as plt


def load_data(filename):
    x, y = [], []
    with open(filename, 'r', encoding='utf-8') as f:
        for line in f.readlines()[1:]:
            if line.strip():
                parts = line.strip().split(';')
                x.append(float(parts[0]))
                y.append(np.nan if parts[1] == 'NaN' else float(parts[1]))
    return np.array(x), np.array(y)


def linear_interp(x1, y1, x2, y2, x):
    return y1 + (y2 - y1) * (x - x1) / (x2 - x1)


def quadratic_interp(xp, yp, x):
    A = np.array([[xp[0]**2, xp[0], 1], [xp[1]**2, xp[1], 1], [xp[2]**2, xp[2], 1]])
    coef = np.linalg.solve(A, yp)
    return coef[0]*x**2 + coef[1]*x + coef[2]


def find_nearest(x, y, idx, n):
    left, right = [], []
    for i in range(idx-1, -1, -1):
        if not np.isnan(y[i]):
            left.append((x[i], y[i]))
            if len(left) == n: break
    for i in range(idx+1, len(x)):
        if not np.isnan(y[i]):
            right.append((x[i], y[i]))
            if len(right) == n: break
    return left, right

def interpolate(x, y, method='linear'):
    y_filled = y.copy()
    for i in range(len(x)):
        if np.isnan(y[i]):
            if method == 'linear':
                left, right = find_nearest(x, y, i, 1)
                if left and right:
                    y_filled[i] = linear_interp(left[0][0], left[0][1], right[0][0], right[0][1], x[i])
            else:  # quadratic
                left, right = find_nearest(x, y, i, 2)
                points = []
                if len(left) >= 2 and len(right) >= 1:
                    points = left[:2] + right[:1]
                elif len(left) >= 1 and len(right) >= 2:
                    points = left[:1] + right[:2]
                elif len(left) >= 3:
                    points = left[:3]
                elif len(right) >= 3:
                    points = right[:3]
                if len(points) >= 3:
                    points.sort(key=lambda p: p[0])
                    y_filled[i] = quadratic_interp([p[0] for p in points], [p[1] for p in points], x[i])
    return y_filled


x, y = load_data('lab2_data.csv')
nan_idx = np.where(np.isnan(y))[0]


plt.plot(x, y, 'bo-', label='Исходные данные')
plt.scatter(x[nan_idx], [plt.ylim()[0]]*len(nan_idx), color='red', marker='x', label='Пропуски')
plt.legend()
plt.show()

y_lin = interpolate(x, y, 'linear')
y_quad = interpolate(x, y, 'quadratic')

print("Линейная:", [f"x={x[i]:.0f}, y={y_lin[i]:.2f}" for i in nan_idx])
print("Квадратичная:", [f"x={x[i]:.0f}, y={y_quad[i]:.2f}" for i in nan_idx])


plt.plot(x, y_lin, 'g-', label='Линейная интерполяция')
plt.plot(x, y_quad, 'r-', label='Квадратичная интерполяция')
plt.scatter(x[nan_idx], y_lin[nan_idx], color='green', marker='o', facecolors='none')
plt.scatter(x[nan_idx], y_quad[nan_idx], color='red', marker='s', facecolors='none')
plt.legend()
plt.show()
