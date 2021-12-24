#include "Simulation.h"

//--------------------------------------------------------------
Simulation::Simulation(){

}

//--------------------------------------------------------------
Simulation::~Simulation(){

}

//--------------------------------------------------------------
void Simulation::setup(float x, float y, float w, float h, int pop){

    // Set simulation parameters
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;

    // Randomly distribute the hosts within the simulation area
    for(int i = 0; i < pop; i++)
    {
        Host host;
        host.x = rand() % static_cast<int>(w - 1) + 1;
        host.y = rand() % static_cast<int>(h - 1) + 1;
        host.destinationX = host.x;
        host.destinationY = host.y;
        host.infectionTime = 0;
        host.hostsInfected = 0;
        host.status = susceptible;

        // Set first host to be infectious
        if(i == 0)
        {
            host.status = infectious;
        }

        hosts.push_back(host);
    }

    // Update snapshot data
    snapshot.susceptible = 0;
    snapshot.infectious = 0;
    snapshot.recovered = 0;
    snapshot.r0 = 0;

    for(Host& host : hosts)
    {
        switch(host.status)
        {
            case susceptible:
                snapshot.susceptible++;
                break;

            case infectious:
                snapshot.infectious++;
                break;

            case recovered:
                snapshot.recovered++;
                break;

            default:
                break;
        }
    }
}

//--------------------------------------------------------------
void Simulation::update(){

    // Update host positions
    for(Host& host : hosts)
    {
        // If host has reached it's set destination
        if((static_cast<int>(host.destinationX) == static_cast<int>(host.x)) && (static_cast<int>(host.destinationY) == static_cast<int>(host.y)))
        {   
            // Calculate a new destination
            // host.destinationX = host.x + (rand() % static_cast<int>(2*w + 1)) - w;
            // host.destinationY = host.y + (rand() % static_cast<int>(2*h + 1)) - h;
            host.destinationX = rand() % static_cast<int>(w - 1) + 1;
            host.destinationY = rand() % static_cast<int>(h - 1) + 1;

            // // Ensure destination doesn't cross the boundary
            // if(host.destinationX <= 0)
            // {
            //     host.destinationX = 1;
            // }
            // else if(host.destinationX >= w)
            // {
            //     host.destinationX = w - 1;
            // }

            // if(host.destinationY <= 0)
            // {
            //     host.destinationY = 1;
            // }
            // else if(host.destinationY >= h)
            // {
            //     host.destinationY = h - 1;
            // }
        }

        // Move host one step towards destination
        if(host.destinationX < host.x)
        {
            host.x -= 1;
        }
        else if(host.destinationX > host.x)
        {
            host.x += 1;
        }

        if(host.destinationY < host.y)
        {
            host.y -= 1;
        }
        else if(host.destinationY > host.y)
        {
            host.y += 1;
        }
    }

    // Update spread of infection
    for(Host& host : hosts)
    {
        // If still infectious
        if(host.status == infectious)
        {
            // If recovery time has passed, remove infection
            if(host.infectionTime >= 300)
            {
                host.status = recovered;
                host.infectionTime = 0;
            }
            else
            {
                // Check if any susceptible hosts are within vicinity
                for(Host& target : hosts)
                {
                    // If so, determine if infection should be passed on
                    if((std::abs(host.x - target.x) <= 3.0) && (std::abs(host.y - target.y) <= 3.0) && (target.status == susceptible))
                    {
                        if((rand() % 101) >= 50)
                        {
                            target.status = infectious;
                            host.hostsInfected++;
                        }
                    }
                }
                host.infectionTime++;
            }         
        }
    }

    // Update snapshot data
    snapshot.susceptible = 0;
    snapshot.infectious = 0;
    snapshot.recovered = 0;
    snapshot.r0 = 0;

    for(Host& host : hosts)
    {
        switch(host.status)
        {
            case susceptible:
                snapshot.susceptible++;
                break;

            case infectious:
                snapshot.infectious++;
                snapshot.r0 += host.hostsInfected;
                break;

            case recovered:
                snapshot.recovered++;
                break;

            default:
                break;
        }
    }

    if(snapshot.infectious != 0)
    {
        snapshot.r0 /= snapshot.infectious;
    }
}

//--------------------------------------------------------------
void Simulation::draw(){
    
    // Draw simulation zone
    ofSetColor(255);
    ofNoFill();
    ofDrawRectangle(x, y, w, h);

    // Draw hosts
    for(Host& host : hosts)
    {
        switch(host.status)
        {
            case susceptible:
                ofSetColor(50, 150, 255); // Blue
                ofDrawCircle(x + host.x, y + host.y, 1.0);
                break;

            case infectious:
                ofSetColor(255, 0, 0); // Red
                ofDrawCircle(x + host.x, y + host.y, 1.0);
                break;

            case recovered:
                ofSetColor(0, 255, 0); // Green
                ofDrawCircle(x + host.x, y + host.y, 1.0);
                break;

            default:
                break;
        }
    }
}

//--------------------------------------------------------------
Data Simulation::getSnapshot(){

    return snapshot;
}
