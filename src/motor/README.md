# Virtual-Motor-Controller-Sensor-Fusion-Model


## Figuring out physics for a DC Motor when it comes to Torque

Equation for the **Electric** side of the motor:


$
V = L\dfrac{d_i}{d_t} + Ri + K_ew
$

**Mechanical** side equation: 


$
J\dfrac{dw}{dt} = t - bw - t_{load}
$

**Additional notes:**

$V$ = applied voltage

$L$ = armature inductance

$R$ = armature resistance

$i$ = armature current

$K_e$ =  back-EMF constance

$w$ = angular velocity

$J$ = intertia

$b$ = vicious friction coefficient

$t$ = motor torque

$t_{load}$ = external load torque

## Since this project is going for a first-pass simulation, this will ignore inductance $L$.
If $L$ = 0, then we simplify our current:


$
i = \dfrac{V-K_ew}{R}
$


Take this torque: 


$
t = K_t \cdot \dfrac{V-K_ew}{R}
$

Mechanical equation


$
J\dfrac{dw}{dt} = t -bw - t_{load} => 
\dfrac{dw}{dt} = \dfrac{t-bw-t_{load}}{J}
$



