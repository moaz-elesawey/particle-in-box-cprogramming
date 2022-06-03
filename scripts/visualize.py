import numpy as np
import netCDF4 as nc
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation, PillowWriter, FFMpegWriter


ncfile = "result.nc"

ds = nc.Dataset(ncfile)

N  = ds.dimensions['N'].size
NT = ds.dimensions['NT'].size

a = ds.dimensions['a'].size
b = ds.dimensions['b'].size

x = np.linspace(0, a, N)
y = np.linspace(0, b, N)

xx, yy = np.meshgrid(x, y)

psi = np.loadtxt("density.txt").reshape(NT, N, N)
den = np.loadtxt("wavefunction.txt").reshape(NT, N, N)

def plot_sample():
    fig, axs = plt.subplots(nrows=2, ncols=2, figsize=(9, 7),
            sharex=True, sharey=True)

    axs[0,0].contourf(den[  0], cmap=plt.cm.magma)
    axs[0,1].contourf(den[250], cmap=plt.cm.magma)
    axs[1,0].contourf(den[500], cmap=plt.cm.magma)
    axs[1,1].contourf(den[999], cmap=plt.cm.magma)

    plt.show()


def plot_live(den, save=False):

    fig = plt.figure(figsize=(12, 6))
    ax1 = fig.add_subplot(121, projection='3d')
    ax2 = fig.add_subplot(122)

    zlim = np.min(den), np.max(den)

    def animate(i):
        if i % 10 == 0:
            print("writing simulation of timestep t = {:>3} of {}".format(i, NT))

        ax1.clear()
        ax2.clear()

        ax1.plot_surface(xx, yy, den[i, :, :], cstride=4, rstride=4,
                cmap=plt.cm.magma)

        ax1.set_zlim(zlim)

        ax2.contourf(den[i, :, :], vmin=-1, cmap=plt.cm.magma)

    ani = FuncAnimation(fig, animate, NT, interval=20, blit=False)

    if save:
        vidwriter = FFMpegWriter(fps=30)
        ani.save("PIB_Simulation.mp4", writer=vidwriter)
    else:
        plt.show()

plot_live(den, save=True)

