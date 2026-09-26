**FPGA-Based SA-TCN Spectrum Sensing Framework for Cognitive Radio Networks**

An FPGA-based intelligent spectrum sensing framework for detecting occupied and free channels in the FM band using a Self-Attention Temporal Convolutional Network (SA-TCN), RTL-SDR, and the Digilent Cmod A7-35T FPGA.

Overview

Cognitive Radio (CR) networks require efficient spectrum sensing to identify unused frequency bands while avoiding interference with licensed users. This project develops a real-time spectrum sensing framework that combines:

Software Defined Radio (SDR) for RF signal acquisition

Signal preprocessing and FFT-based spectral representation

A Self-Attention Temporal Convolutional Network (SA-TCN) for spectrum classification

FPGA hardware acceleration using the Digilent Cmod A7-35T

UART communication between the host system and FPGA

The system monitors the 88–108 MHz FM band and classifies spectrum channels as Free or Occupied.

Project Objective

To design and implement an FPGA-based SA-TCN framework on the Digilent Cmod A7-35T for real-time FM spectrum occupancy detection in Cognitive Radio networks.



The project uses the RadioML 2016 dataset containing labeled I/Q signal samples.

The project report describes the dataset split as:

Dataset

Samples

Training

17,000

Validation

3,000

Testing

3,000

A 128-point FFT is used to generate spectral representations for model training and evaluation.

The dataset is not included in this repository because of its size. Obtain the dataset separately and place it in the appropriate local dataset directory.

Hardware

Digilent Cmod A7-35T

The FPGA processing platform is the Digilent Cmod A7-35T, based on the Xilinx Artix-7 XC7A35T FPGA.

Key resources/features include:

Artix-7 XC7A35T FPGA

Configurable logic blocks

DSP slices

Block RAM (BRAM)

512 KB SRAM

4 MB Quad-SPI Flash

USB-JTAG programming

USB-UART bridge

3.3 V logic

RTL-SDR

The RTL-SDR is used as the RF front-end for acquiring real-time radio signals.

The project uses the Nooelec NESDR SMArt SDR with a temperature-compensated crystal oscillator.

Used frequency range:

88 MHz – 108 MHz

The SDR provides digital I/Q (In-phase and Quadrature) samples to the host computer.

Software and Tools

Tool

Purpose

Python 3.10.11

RF acquisition, preprocessing and model development

Vivado 2024.1

FPGA design, synthesis, implementation and bitstream generation

MATLAB/Simulink

Model development and hardware-oriented workflow

HDL Coder

Generation of synthesizable hardware modules

Google Colab

Model training and evaluation

RTL-SDR software

RF signal acquisition

Working Process

Step 1 — RF Signal Acquisition

The RTL-SDR captures RF signals from the FM band and converts them into digital I/Q samples.

Step 2 — Preprocessing

The acquired samples are processed before being supplied to the neural network.

The project uses FFT-based spectral representation and filtering for feature extraction.

Step 3 — SA-TCN Classification

The processed signal representation is passed to the SA-TCN model.

The model learns temporal and spectral patterns associated with channel occupancy.

Step 4 — FPGA Inference

The trained model is optimized using fixed-point quantization and deployed on the Cmod A7-35T FPGA.

Step 5 — Spectrum Decision

The FPGA produces a classification indicating whether the monitored channel is:

FREE

or

OCCUPIED

Step 6 — Cognitive Radio Decision

A free channel can be considered for opportunistic communication, while occupied channels are avoided to reduce interference with existing transmissions.

Implementation Flow

RadioML 2016 Dataset
          │
          ▼
   Dataset Preparation
          │
          ▼
    SA-TCN Training
          │
          ▼
 Model Optimization /
 Fixed-Point Quantization
          │
          ▼
 HDL / Hardware Generation
          │
          ▼
  Cmod A7-35T FPGA
          │
          ▼
 Real-Time Spectrum Sensing
          │
          ▼
   Free / Occupied

Results

The implemented system was tested for spectrum sensing in the 88–108 MHz FM band.

According to the project evaluation:

The RTL-SDR successfully scanned the FM band and captured real-time I/Q samples.

Signal energy and spectral information were used for spectrum analysis.

The system identified multiple free and occupied spectrum slots under controlled laboratory conditions.

UART communication was used for data exchange between the host system and FPGA.

The FPGA provided spectrum availability decisions through its hardware interface.

The SA-TCN architecture demonstrated effective classification of spectrum occupancy.

Kernel size 3 was reported as providing optimal accuracy and stability in the evaluated model configuration.

Why FPGA?

FPGA implementation provides hardware-level parallelism and can reduce the latency associated with real-time signal processing.

In this project, FPGA acceleration is used to move the trained SA-TCN inference toward a resource-efficient hardware implementation suitable for real-time cognitive radio spectrum sensing.

Applications

The proposed framework can be applied to:

Cognitive Radio Networks

Dynamic Spectrum Access

Spectrum Monitoring

IoT Communication

FM Band Monitoring

Intelligent Wireless Communication Systems

Hardware-Accelerated Signal Processing

Future Work

Potential extensions described in the project include:

Extending spectrum monitoring beyond the FM band

Implementing real-time adaptive thresholding

Developing more autonomous dynamic spectrum access mechanisms

Exploring advanced deep learning models with FPGA acceleration

Reducing inference latency and improving classification performance

Supporting secure bidirectional communication over identified free channels

Further over-the-air validation of the complete system

Project Team

Ashwika A
Franklen Joseph A G
K R Gobishankar

Department of Electronics and Communication Engineering
Dr. N.G.P. Institute of Technology, Coimbatore

Project Keywords

FPGA SA-TCN Spectrum Sensing Cognitive Radio RTL-SDR Artix-7 Cmod A7-35T Deep Learning I/Q Signals FM Spectrum Dynamic Spectrum Access IoT Signal Processing

Note

This repository contains the implementation and supporting material for an academic project on FPGA-based intelligent spectrum sensing. The RadioML dataset and other large external datasets are not included in the repository.
