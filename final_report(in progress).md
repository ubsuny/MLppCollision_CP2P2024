## Event Reconstruction and Signal Extraction: Bridging B Meson and Higgs Boson Decays

Earlier we used ROOT and C++ to extract B-meson signal from the background. The background was not that noisy and the B-meson peak was conspicuous. The idea was that if we need to study the properties of exotic particles such as their mass, we need to isolate them from the background. We separated charged B-mesons and calculated CP Asymmetry. However, it was a relatively clean signal with very little background but it may not be the case with other particles such as Higgs Boson. Higgs can also decay through multiple channels and one of the decays is $(\ H \rightarrow [ZZ][4l] \)$ This decay has an overlapping signal and background for Z boson jets and we can not eyeball the results to estimate the jet mass. For such cases, we can use Machine Learning techniques to identify signal. Once we have identified the signal we can measure its properties such as mass e.t.c.

### Signal Extraction: Higgs Boson Decay

#### Collision and Detection

Higgs bosons, when produced in high-energy collisions, can decay into various final states. One important decay mode is into two Z bosons, each of which further decays into four leptons (electrons or muons).

#### Signal Extraction with XGBoost

In the analysis of Higgs boson decays, machine learning techniques like XGBoost are employed to separate signal from background:

- **Feature Extraction**: Relevant features such as lepton momenta, angles, and invariant masses are extracted from the reconstructed events.

- **Training the XGBoost Model**: A machine learning model (e.g., XGBoost) is trained on simulated events to learn the characteristic features of signal and background events.

- **Signal Extraction**: The trained model is applied to experimental data, assigning a "score" to each event indicating the likelihood of being a signal. Events with high scores are considered potential signal candidates.

### Bridging the Gap

While the methods used for B meson and Higgs boson analyses may seem distinct, they share a common underlying principle: the separation of signal from background.

- Both analyses start with the reconstruction of events based on the known properties of the particles involved.

- They then employ statistical or machine learning techniques to distinguish between signal events of interest and background events.

- Whether using ROOT for B meson decays or XGBoost for Higgs boson decays, the goal remains the same: to maximize the signal-to-background ratio and enhance the sensitivity of the analysis.

By understanding and applying these principles, we can extract valuable information from complex data.


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

## Results

Just by looking at the plot for f_massjj (Mass of Z-boson jet) we may think that the signal is around 375 GeV but from our Decision Boundary Plot, we can see most of the Z-boson jest mass is concentrated around **125 GeV** (The red dots). This is in fact consistent with the known Z-boson jet mass for this decay channel i.e. **124.79 GeV** (See reference below). This example elucidates the importance of ML techniques and how it can be used to handle noisy backgrounds.


## Conclusion

Using the XGBoost classifier in the CMS LPC environment, we were able to build a Boosted Decision Tree (BDT) model that effectively separates signal events (Higgs decay) from background events. This analysis contributes to the understanding of the Higgs boson decay process and helps in identifying key observables that can discriminate between signal and background events.

## Reference
Measurement of the Higgs boson mass in the H → ZZ⁎ → 4ℓ and H → γγ channels with s=13 TeV pp collisions using the ATLAS detector. Physics Letters B, 784, 345-366, 2018. 
