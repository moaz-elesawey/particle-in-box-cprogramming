import numpy as np
import h5py
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation, PillowWriter, FFMpegWriter


h5file = "result.h5"

ds = h5py.File(h5file)

xx, yy = ds["xx"][:], ds["yy"][:]
psi, den = ds["wavefunction"][:], ds["density"][:]

NT = den.shape[0]
N  = den.shape[1]

def plot_live(den, psi, save=False):

    fig = plt.figure(figsize=(12, 6))

    ax1 = fig.add_subplot(121)
    ax2 = fig.add_subplot(122)

    zlim = np.min(den), np.max(den)

    def animate(i):
        if i % 10 == 0:
            print("writing simulation of timestep t = {:>3} of {}".format(i, NT))

        ax1.clear()
        ax2.clear()

        ax1.imshow(den[i], cmap=plt.cm.jet)

        ax2.imshow(psi[i], cmap=plt.cm.jet)

        ax1.set_title("Density $|\Psi|^2$")
        ax2.set_title("Wave Function $\Psi$")


    ani = FuncAnimation(fig, animate, NT, interval=20, blit=False)

    if save:
        vidwriter = FFMpegWriter(fps=10)
        ani.save("PIB_Simulation.mp4", writer=vidwriter)
    else:
        plt.show()

plot_live(den, psi, save=False)

