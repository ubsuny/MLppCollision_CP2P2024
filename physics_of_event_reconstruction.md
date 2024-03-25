# Particle Physics and Event Reconstruction

## Introduction
Particle physics aims to understand the fundamental building blocks of the universe and the forces that govern their interactions. Collider experiments play a crucial role in this endeavor, where particles are accelerated to high energies and collided to study their behavior and interactions. Event reconstruction is a fundamental aspect of collider experiments, involving the detection and analysis of particles produced in these collisions.

## Collider Physics Overview
Collider experiments involve accelerating particles to high energies using particle accelerators and colliding them at designated collision points within detectors. These collisions produce a multitude of particles, which are then detected and analyzed to study their properties and interactions.

### Accelerators
Particle accelerators, such as the Large Hadron Collider (LHC) at CERN, accelerate particles to high energies using electromagnetic fields. These particles are typically protons or heavy ions, and they are accelerated to velocities close to the speed of light.

### Collisions
Accelerated particles are collided head-on or at grazing angles at collision points within detectors. High-energy collisions produce a wide range of particles, including known particles as well as new, potentially undiscovered ones. These collisions mimic conditions similar to those present in the early universe, allowing scientists to study fundamental physics phenomena.

### Detectors
Detectors surrounding the collision points are designed to detect and measure the properties of particles produced in the collisions. These detectors are complex instruments composed of various sub-detectors, each optimized for detecting different types of particles and measuring specific properties such as energy, momentum, and charge.

## Event Reconstruction Process
Event reconstruction is the process of identifying and analyzing particles produced in collider collisions based on the signals recorded by detectors. The event reconstruction process typically involves several steps:

1. **Signal Detection**: Detectors record signals produced by particles interacting with detector materials. These signals include energy deposits, ionization trails, and electromagnetic radiation emitted by particles.

2. **Particle Identification**: Based on the recorded signals, detectors identify the types of particles produced in the collisions. Different types of particles leave distinct signatures in detectors, allowing for particle identification based on their properties such as energy loss, trajectory, and interaction patterns.

3. **Trajectory Reconstruction**: Detectors reconstruct the trajectories of particles based on the signals they produce as they pass through the detector layers. Trajectory reconstruction allows scientists to determine the paths particles took after the collision and infer information about their origins and interactions.

4. **Energy Measurement**: Detectors measure the energy deposited by particles as they interact with detector materials. Energy measurements are crucial for determining the total energy of particles and identifying high-energy particles that may indicate the presence of new physics phenomena.

5. **Interaction Analysis**: Scientists analyze the detected particles' interactions to study fundamental physics phenomena, such as particle decays, particle scattering, and the production of new particles. Analysis of particle interactions provides insights into the underlying physics principles governing particle behavior and interactions.

## Present analysis
The code performs event reconstruction and analysis of data recorded by detectors in collider experiments. It applies selection criteria to identify specific particle decays, reconstructs their invariant masses, and analyzes their properties to study fundamental physics phenomena such as CP Asymmetry.

![Screenshot 2024-03-25 115940](https://github.com/ubsuny/MLppCollision_CP2P2024/assets/143828394/6e31efc0-accc-40da-ae21-985c86a70171)

### Particle Identification
The code identifies particles based on their properties, such as probabilities of being certain particle types (e.g., kaons, pions), charges, and momenta. Particle identification is essential for isolating specific particle decays and studying their properties.

### Invariant Mass Reconstruction
The code reconstructs the invariant masses of particles produced in specific decay channels using their measured momenta. Invariant mass reconstruction allows for precise determination of particle masses and the study of particle decay processes.

### Background Suppression
The code applies selection criteria to suppress background contributions from events not corresponding to the decay channels of interest. Background suppression techniques enhance the signal-to-background ratio, improving the sensitivity and accuracy of the analysis.

## Results
On loading and running the C++ macro on ROOT software, the following output is generated:

![Screenshot 2024-03-25 115722](https://github.com/ubsuny/MLppCollision_CP2P2024/assets/143828394/fa7d0b15-e9cd-4771-b30b-305ad16b4b75)


![Screenshot 2024-03-25 120256](https://github.com/ubsuny/MLppCollision_CP2P2024/assets/143828394/3cbd237b-506d-4479-9a5a-1e24f1304672)

The results successfully reproduce the mass of charged B-mesons i.e 5.279 GeV and also indicate a difference in the number of B+ and B- mesons, the reason for this asymmetry is still not fully understood but is a well-observed phenomenon.
Measured CP Asymmetry is -0.0359549 with an uncertainty of 0.00751989.
