% Clear workspace and command window
clear; clc; close all;

% Load data from CSV file
filename = 'test.csv';  % Ensure this file is in the same folder
data = readmatrix(filename); % Read CSV file

% Extract columns
days = data(:, 1);        % Day number
Earth_X = data(:, 2);     % Earth's X position
Earth_Y = data(:, 3);     % Earth's Y position
Moon_X = data(:, 4);      % Moon's X position
Moon_Y = data(:, 5);      % Moon's Y position

% Assume 3rd coordinate as 0 (for 3D effect)
Earth_Z = zeros(size(Earth_X)); 
Moon_Z = zeros(size(Moon_X));

% Plot in 3D
figure;
hold on; grid on; axis equal;
xlabel('X Position (km)'); ylabel('Y Position (km)'); zlabel('Z Position (km)');
title('3D Orbits of Earth and Moon');
view(45, 30); % Adjust 3D angle

% Plot the Earth and Moon's orbits with new colors
plot3(Earth_X, Earth_Y, Earth_Z, 'g', 'LineWidth', 3); % Earth Orbit (Thick Green)
plot3(Moon_X, Moon_Y, Moon_Z, 'b--', 'LineWidth', 2, 'Marker', 'o', 'MarkerSize', 3); % Moon Orbit (Dashed Blue with Markers)

% Plot the Sun (center) in Red
plot3(0, 0, 0, 'ro', 'MarkerSize', 10, 'MarkerFaceColor', 'red');  

% Add legend
legend({'Earth Orbit (Green)', 'Moon Orbit (Blue)', 'Sun (Red)'}, 'Location', 'best');

% Display the plot
hold off;
