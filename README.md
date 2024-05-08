# Analysis of Higgs Decay into Two Z-Bosons and 4 Leptons

In this analysis, we investigated the decay of the Higgs boson into two Z-bosons, each of which subsequently decays into two leptons (4 leptons in total). The goal was to distinguish between signal events (Higgs boson decay) and background events (other processes that mimic the signal) based on certain observables.

## Data

We utilized data samples obtained from the HZZ4LeptonsAnalysis, containing events of Higgs decay into two Z-bosons and 4 leptons. The data was divided into two categories:
- Background: Events from processes other than Higgs decay that can mimic the signal.
- Signal (VV): Events representing the decay of the Higgs boson into two Z-bosons.

## Methodology

To separate the signal from the background, we employed the XGBoost (Extreme Gradient Boosting) algorithm, which is a powerful machine learning technique for classification tasks.

 1. Split the data into input features (X) and target labels (Y). X= f_massjj,f_mass4l Y=1,0 (Signal or background).
 2. Split the data into training and testing datasets.
 3. Define the model: boosted decision tree model from the xgboost library used.
 4. Run the training.
 5. Verify plot performance (ROC curve)
 6. Plot the decision boundary between signal and background events using the input features (f_massjj and 
f_mass4l)

### XGBoost (BDT)

We trained an XGBoost classifier using the provided features (observables) from the data samples. The classifier was trained to distinguish between signal and background events based on the observed features. By optimizing the model's performance, we aimed to achieve a clear separation between the signal and background data points.

## Computing Environment

For this analysis, we utilized the CMS LPC (Large Hadron Collider Physics Center) environment instead of Docker. The CMS LPC environment offers several advantages for particle physics analysis:

1. **Access to CMS Data**: The LPC environment provides direct access to the CMS experiment's data and computing resources, facilitating efficient analysis workflows.

2. **Specialized Software Stacks**: It comes with pre-installed software stacks tailored for CMS analysis, including ROOT, CMSSW, and various analysis tools, making it easy to set up and run particle physics analyses.

3. **High-Performance Computing**: LPC resources offer high-performance computing capabilities optimized for particle physics workloads, allowing for faster data processing and analysis.

4. **Community Support**: Being part of the CMS collaboration, LPC provides access to a large community of researchers and experts who can provide support and guidance for analysis tasks.

Using the CMS LPC environment streamlines the analysis process and ensures compatibility with CMS collaboration standards and resources.

## Data visualization

We used ROOT file for Higgs decay to two Z-bosons and 4 leptons. We have plotted the jet masses using **uproot** and **matplotlib**. We can see that the background and signal is overlapping for Z boson jets. Using **Xgboost** (a machine learning algorithm) we separate background and signal data points. 

![Screenshot 2024-05-08 192020](https://github.com/ubsuny/MLppCollision_CP2P2024/assets/143828394/3bcb526c-718c-4037-b743-3f75776c4145)

## Decision Boundary Plot

The decision boundary plot allows us to visualize how the model distinguishes between signal and background events based on these input features. This visualization helps us understand the classification behavior of the model and identify regions where it may struggle to make accurate predictions.

![Screenshot 2024-05-08 192046](https://github.com/ubsuny/MLppCollision_CP2P2024/assets/143828394/4fbabfa2-6263-47cf-9e51-eb309347fed2)


## Conclusion

Using the XGBoost classifier in the CMS LPC environment, we were able to build a Boosted Decision Tree (BDT) model that effectively separates signal events (Higgs decay) from background events. This analysis contributes to the understanding of the Higgs boson decay process and helps in identifying key observables that can discriminate between signal and background events.

# Reconstruction of charged B-mesons and calculating CP Asymmetry (Why the Universe has more matter than antimatter?).

# Introduction to CP Asymmetry
In the context of the provided code for event reconstruction and analysis, the concept of CP (Charge-Parity) asymmetry plays a significant role in understanding the fundamental properties of particles and their interactions. CP asymmetry refers to the difference in the behavior of particles and antiparticles under the combined operations of charge conjugation (C) and parity transformation (P). Specifically, the measurement of CP asymmetry provides insights into the violation of CP symmetry in particle physics, which is a phenomenon observed in certain particle decays where the behavior of particles and antiparticles differ. In the code, calculating the CP asymmetry involves analyzing the distribution of reconstructed invariant masses of B⁺ and B⁻ mesons, which are charged B-mesons decaying into three charged hadrons. By quantifying the asymmetry between the number of B⁺ and B⁻ decays, the code aims to elucidate any deviations from CP symmetry, shedding light on the underlying dynamics of particle interactions. Thus, the calculation of CP asymmetry in the code serves as a crucial tool for probing fundamental symmetries in particle physics.

# Decay Channel

The decay channel used for this analysis involves the decay of a charged B-meson (B⁺ or B⁻) into three hadrons. This decay process is mediated by the weak force and is one of the important channels studied in particle physics experiments. The three hadrons typically consist of a combination of mesons (particles composed of a quark and an antiquark) or baryons (particles composed of three quarks).

The decay process can be represented by the following general formula:

$$ B^\pm \rightarrow H_1 H_2 H_3 $$

where H_1, H_2, and H_3 represent the three hadrons produced in the decay. The specific particles involved in the decay depend on the particular decay mode and the properties of the B-meson.

This decay channel is of particular interest in studies of CP violation and particle interactions. By analyzing the properties of the final-state hadrons, we can gain insights into the underlying dynamics of the weak interactions and probe for possible deviations from the predictions of the Standard Model of particle physics. This will allow us to answer the basic question, "Why the Universe have more matter than antimatter?" Theoretically, matter and antimatter should have been produced in equal proportions, annihilating each other out! We know this is not the case. 


# Investigating CP Asymmetry with Colliders

Colliders play a crucial role in investigating CP asymmetry by providing environments where high-energy collisions between particles occur, allowing us to study the behavior of matter and antimatter particles in detail. Here's how colliders help us investigate CP asymmetry:

1. **Production of Particle-Antiparticle Pairs**: Colliders, such as the Large Hadron Collider (LHC) at CERN, accelerate particles to extremely high energies and collide them head-on or at grazing angles. These collisions produce large numbers of particle-antiparticle pairs, including B-mesons and their antiparticles (B⁺ and B⁻). By analyzing the properties of these particles and their decays, we can study CP asymmetry.

2. **Decay Processes**: B-mesons, can decay into a variety of final states. By studying the decay patterns and rates of B-mesons and their antiparticles, scientists can look for differences in the behavior of particles and antiparticles, which may indicate CP violation.

3. **Precise Measurements**: Colliders provide high collision energies and sophisticated detectors that allow for precise measurements of particle properties, such as momentum, energy, and decay products. These measurements are essential for accurately determining the properties of B-mesons and their decays, enabling scientists to study CP asymmetry with high precision.

4. **Search for New Physics**: CP violation beyond what is predicted by the Standard Model of particle physics could indicate the presence of new fundamental particles or interactions. Colliders with high collision energies allows us to explore energy regimes where new physics may manifest, providing opportunities to search for phenomena that could explain the observed CP asymmetry.

5. **Comparison with Theoretical Predictions**: Experimental measurements of CP asymmetry at colliders can be compared with theoretical predictions based on the Standard Model and its extensions. Any deviations between experimental observations and theoretical predictions may indicate the presence of new physics phenomena or inconsistencies in our current understanding of particle interactions.

Overall, colliders play a central role in investigating CP asymmetry by providing the means to produce, study, and analyze large numbers of particles and their interactions. Through precise measurements and comparisons with theoretical predictions, colliders help advance our understanding of the fundamental symmetries and properties of the universe.


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

The results successfully reproduce the mass of charged B-mesons i.e **5.279 GeV** and also indicate a difference in the number of B+ and B- mesons, the reason for this asymmetry is still not fully understood but is a well-observed phenomenon.
Measured CP Asymmetry is **-0.0359549** with an uncertainty of **0.00751989**.
