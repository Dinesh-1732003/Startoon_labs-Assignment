import numpy as np
import matplotlib.pyplot as plt

def find_peaks(signal):
    maxima = []
    minima = []

    for i in range(1, len(signal) - 1):
        if signal[i] > signal[i-1] and signal[i] > signal[i+1]:
            maxima.append(i)
        elif signal[i] < signal[i-1] and signal[i] < signal[i+1]:
            minima.append(i)
    
    return maxima, minima

def plot_peaks(signal, maxima, minima):
    plt.figure(figsize=(10, 6))
    plt.plot(signal, label='Signal')
    plt.scatter(maxima, [signal[i] for i in maxima], color='red', label='Maxima')
    plt.scatter(minima, [signal[i] for i in minima], color='blue', label='Minima')
    plt.xlabel('Index')
    plt.ylabel('Signal Value')
    plt.title('Signal with Peaks')
    plt.legend()
    plt.show()
signal_1 = np.loadtxt('Data_1.txt')
signal_2 = np.loadtxt('Data_2.txt')
maxima_1, minima_1 = find_peaks(signal_1)
plot_peaks(signal_1, maxima_1, minima_1)

maxima_2, minima_2 = find_peaks(signal_2)
plot_peaks(signal_2, maxima_2, minima_2)

print("Data_1 Maxima Indices:", maxima_1)
print("Data_1 Minima Indices:", minima_1)
print("Data_2 Maxima Indices:", maxima_2)
print("Data_2 Minima Indices:", minima_2)
