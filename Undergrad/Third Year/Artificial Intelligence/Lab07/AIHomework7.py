import numpy as np

def sigmoid(x, derive=False):
    if derive:
        return x * (1 - x)
    return 1 / (1 + np.exp(-x))

# Define the data set XOR
X = np.array([
    [1, 1, 1, 0, 1, 1, 1],
    [0, 0, 1, 0, 0, 1, 0],
    [1, 0, 1, 1, 1, 0, 1],
    [1, 0, 1, 1, 0, 1, 1],
    [0, 1, 1, 1, 0, 1, 0],
    [1, 1, 0, 1, 1, 1, 1],
    [1, 0, 1, 0, 0, 1, 0],
    [1, 1, 1, 1, 1, 1, 1],
    [1, 1, 1, 1, 0, 1, 1]
    ])

y = np.array([
    [0],
    [1],
    [2],
    [3],
    [4],
    [5],
    [6],
    [7],
    [8],
    [9]
     ])

#y = np.array([
#    [1, 0, 0, 0, 0, 0, 0, 0, 0, 0],
#    [0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
#    [0, 0, 1, 0, 0, 0, 0, 0, 0, 0],
#    [0, 0, 0, 1, 0, 0, 0, 0, 0, 0],
#    [0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
#    [0, 0, 0, 0, 0, 1, 0, 0, 0, 0],
#    [0, 0, 0, 0, 0, 0, 1, 0, 0, 0],
#    [0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
#    [0, 0, 0, 0, 0, 0, 0, 0, 1, 0],
#    [0, 0, 0, 0, 0, 0, 0, 0, 0, 1]
#    ])

#X = np.array([
#    [1, 1, 1],
#    [1, 0, 1],
#    [0, 1, 1],
#    [0, 0, 1],
#])

#y = np.array([[0],
#              [1],
#              [1],
#              [0]
#             ])

# Define a learning rate
eta = 3
# Define the number of epochs for learning
epochs = 10

# Initialize the weights with random numbers
w01 = np.random.random((len(X[0]), 5))
w12 = np.random.random((5, 1))
print("w12", w12)

# Start feeding forward and backpropagate *epochs* times.
for epoch in range(epochs):
    # Feed forward
    z_h = np.dot(X, w01)
    print(z_h)
    a_h = sigmoid(z_h)
    print(a_h)

    z_o = np.dot(a_h, w12)
    print(z_o)
    a_o = sigmoid(z_o)
    print(a_o)

    # Calculate the error
    a_o_error = ((1 / 2) * (np.power((a_o - y), 2)))
    print(a_o_error)

    # Backpropagation
    ## Output layer
    delta_a_o_error = a_o - y
    print(delta_a_o_error)
    delta_z_o = sigmoid(a_o,derive=True)
    print(delta_z_o)
    delta_w12 = a_h
    print(a_h)
    delta_output_layer = np.dot(delta_w12.T,(delta_a_o_error * delta_z_o))
    print(delta_output_layer)

    ## Hidden layer
    delta_a_h = np.dot(delta_a_o_error * delta_z_o, w12.T)
    print(delta_a_h)
    delta_z_h = sigmoid(a_h,derive=True)
    print(delta_z_h)
    delta_w01 = X
    print(delta_w01)
    delta_hidden_layer = np.dot(delta_w01.T, delta_a_h * delta_z_h)
    print(delta_hidden_layer)

    w01 = w01 - eta * delta_hidden_layer
    w12 = w12 - eta * delta_output_layer