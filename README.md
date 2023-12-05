# ENSEA Tiny Shell (enseash)

### Jade Piller and Letícia Moreira

## Introduction

ENSEA Tiny Shell, or enseash, is a micro shell designed for launching commands and displaying information about their execution. This project is part of our first travaux pratique lab assignment, aimed at developing a functional and efficient shell.

## Table of Contents

1. [Considerations](#considerations)
2. [Getting Started](#getting-started)
3. [Features](#features)
4. [Usage](#usage)
5. [Colaborators](#colaborators)

# Considerations

## Difficulties Encountered

### Letícia

1. **Linux:**
   - I did not have much familiarity with the linux system, therefore, having a partner with more experience was great so I could better learn how to use the system and it's functionalities
2. **Remote Programing:**
   - During the first session of the TP, due to adverse circumstances, I had to contribute to the TP remotly. Althought it was a challenge, it helped us implement github good practices and also bettered our communication while commiting our codes to the repository.
3. **Bugs:**
   - During our TP, we encountered many bugs, and fixing them was definetly a challenge, but overall we learned a lot more about the C language library and it's functionalities.
   - Also, when we found ourselves stuck in a problem that we had trouble fixing ourselves, monsieur Tauvel would always analyse our code and explain to us how to better solve it, which made the whole TP session lighter and more instructive.
4. **Familiarity with TP Structure:**
   - Since I am a newcomer in ENSEA, I didn't know what to expect about TPs, however, as time passed, I understood that a TP is much more then a test of our knowledge, but also a learning session in which the teacher guides us into better understanding practical issues regarding the knowledge taught in class.

### Jade

1. **System Processes:**
   - Troubleshooting issues related to precess creation termination and management demanded a meticulous approach to ensure smooth system operation.
2. **Debugging Complexity:**
   - Particularly when dealing with C low level code.
3. **Memory Management:**
   - Managing memory at low level was a challenged and i kinda struggled with segmentation faults that required my constant attention.

## What Was Learned?

Throughout the development of ENSEA Tiny Shell (enseash), several key lessons were learned:

1. **Systems Programming:**
   - Gain a deeper understanding of systems programming, particularly in the context of developing a micro shell.

2. **Process Management:**
   - Learn how to manage processes using fork, exec, and wait, and understand the challenges and intricacies involved in process execution.

3. **Signal Handling:**
   - Acquire knowledge about signal handling, especially in the context of handling SIGINT gracefully for a better user experience.

4. **File I/O and Shell Operations:**
   - Explore file input/output operations and shell operations such as reading commands, executing them, and managing their output.

5. **Code Organization and Documentation:**
   - Understand the importance of well-organized code and the value of documentation in enhancing code readability and maintainability.

6. **Git and GitHub Collaboration:**
   - Develop collaboration skills by working in pairs and effectively utilizing Git and GitHub for version control and project synchronization.

## Most Valuable Lessons

1. **Efficient Resource Management:**
   - Learn how to manage system resources efficiently, considering factors like process creation, execution, and termination.

2. **Practical Application of Theoretical Concepts:**
   - Bridge the gap between theoretical knowledge acquired in the classroom and its practical application in developing a real-world project.

## Getting Started

To get started with enseash, follow these steps:

1. Clone the repository:

   ```bash
   git clone <https://github.com/jadep1103/synthesysjade.git>
   ```

2. Navigate to the project directory:

   ```bash
   cd enseash
   ```

3. Compile the code:

## Features

1. **Welcome Message and Prompt**

   Execute enseash to display a welcome message and a simple prompt:

   ```bash
   $ ./enseash
   Welcome to ENSEA Tiny Shell.
   Type 'exit' to quit.
   enseash %
   ```

2. **Command Execution**

   Enter commands, execute them, and return to the prompt:

   ```bash
   enseash % fortune
   Today is what happened to yesterday.
   enseash % date
   Sun Dec 13 13:19:40 CET 2020
   enseash %
   ```

3. **Shell Output Management**

   Use the command `exit` or `<ctrl>+d` to exit the shell:

   ```bash
   enseash % exit
   Bye bye...
   $

## Usage

Follow these guidelines to use enseash effectively:

- Read the prompt, enter commands, and observe the output.
- Use the `exit` command or `<ctrl>+d` to gracefully exit the shell.
  
## Colaborators
<table>
  <tr>
      <td align="center">
      <a href="#">
        <img src="https://github.com/jadep1103/synthesysjade/assets/72623771/8ba95fc6-6138-4b4e-a3c4-d038aab38c1a" width="200px;" alt="Foto Jade"/><br>
        <sub>
          <b>Jade Piller</b>
          </p>jadep1103
        </sub>
      </a>
    </td>
    <td align="center">
      <a href="#">
        <img src="https://avatars.githubusercontent.com/u/72623771?v=4" width="200px;" alt="Foto Letícia Aires"/><br>
        <sub>
          <b>Letícia Aires</b>
          </p>LeticiaAires
        </sub>
      </a>
    </td>

