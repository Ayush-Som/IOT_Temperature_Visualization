import pandas as pd
import plotly.graph_objects as go

# Step 1: Load data from CSV
data = pd.read_csv('Temp_Data.csv')

# Step 2: Convert the 'Time' column to datetime format (if it's not already)
data['Time'] = pd.to_datetime(data['Time'])

# Step 3: Create a line chart using Plotly
fig = go.Figure(data=go.Scatter(x=data['Time'], y=data['Temp'], mode='lines+markers'))

# Step 4: Customize the plot
fig.update_layout(
    title='Temperature Visualization',
    xaxis_title='Time',
    yaxis_title='Temperature (°C)',
    showlegend=True
)

# Step 5: Display the plot in Jupyter Notebook
fig.show()