#pragma once

typedef struct data {
	int susceptible;
	int infectious;
	int recovered;
} Data;

enum HealthStatus {
	susceptible,
	infectious,
	recovered
};

typedef struct host {
	float x;
	float y;
	HealthStatus status;
} Host;
