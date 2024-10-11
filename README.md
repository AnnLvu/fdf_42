# FDF - 42 Project 🖼️

**FDF** is a 3D wireframe visualizer that reads a matrix from a file and projects it as a 3D landscape. The program allows interactive controls for zooming, rotating, translating, and adjusting projections. 🖥️🔧

## 💻 Installation

To compile and run **FDF**, follow these steps:

### 1. Clone the repository:
```bash
git clone git@github.com:AnnLvu/fdf_42.git
cd fdf_42
   ```   

### 2. Compile the project:
   ```bash   
   make
   ```   

### 3. Run the simulation:
   ```bash   
   ./fdf <path_to_file>
   ```  

---

## 🚀 Usage

Control the program using the following keys:

### Navigation:
- **W**: Move the map up ⬆️
- **S**: Move the map down ⬇️
- **A**: Move the map left ⬅️
- **D**: Move the map right ➡️

### Zoom:
- **+**: Zoom in 🔍
- **-**: Zoom out 🔎

### Rotation:
- **X**: Rotate around the X-axis 🔄
- **Y**: Rotate around the Y-axis 🔁
- **Z**: Rotate around the Z-axis 🔃

### Projection:
- **C**: Switch to isometric projection 🔲
- **V**: Switch to parallel projection 🟧

### Altitude:
- **C**: Increase altitude ⬆️
- **V**: Decrease altitude ⬇️

### Exit:
- **Esc**: Exit the program ❌

## 🧠 How It Works

### Input Format:
The input file should contain a matrix of integers representing the height of each corresponding point in the 3D space. Each row should represent a line of the matrix, and the integers should be separated by spaces.

### Operations:
- The program parses the matrix from the input file and renders the 3D wireframe model. 🖼️
- Zoom, translate, and rotate controls modify the perspective and the position of the map in the window. 🔧
- The projection mode can be switched between isometric and parallel to display the map from different viewpoints. 🔁

### Libraries:
- **MinilibX** — Graphics library provided by 42. 💻🎨

## ⚠️ Known Issues
- Performance might be affected when working with very large maps or files with extremely large matrices. ⚙️
- The program currently does not handle non-integer values or invalid formats in the input file. 🚫
