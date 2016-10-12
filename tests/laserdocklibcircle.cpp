#include <iostream>
#include <string>
#include <cmath>

#include "lib/LaserdockDeviceManager.h"
#include "lib/LaserdockDevice.h"

using namespace std;

typedef bool (LaserdockDevice::*ReadMethodPtr)(uint32_t *);

void print_uint32(string name, LaserdockDevice *d, ReadMethodPtr method){
    uint32_t count = 0;
    bool successful = (d->*method)(&count);

    if(!successful){
        cout << "Failed reading " << name << endl;
        return;
    }

    cout << name << ": " << count << endl;
}



class CircleBuffer {

public:
    CircleBuffer(int count): _count(count), _index(0) {
        _buffer = (uint16_t *) calloc(sizeof(uint16_t), _count*2);

        float x_f, y_f, step_f;
        step_f = 2*M_PI/this->_count;
        int i = 0;

        for(i = 0; i < this->_count; i++){
            x_f = cosf(i*step_f);
            y_f = sinf(i*step_f);
            _buffer[i*2] = float_to_laserdock_xy(x_f);
            _buffer[i*2+1] = float_to_laserdock_xy(y_f);
        }
    }

    ~CircleBuffer() {
        delete _buffer;
    }


    bool fillSamples(LaserdockSample * samples, const uint32_t count){

        uint16_t x, y, rg, b;
        rg = 0xFFFF;
        b = 0xFFFF;

        for(int i = 0; i < count; i++){
            _index++;
            if(_index >= _count) _index = 0;
            x = _buffer[2*_index];
            y = _buffer[2*_index+1];

            samples[i].x = x;
            samples[i].y = y;
            samples[i].rg = rg;
            samples[i].b = b;
        }

        return true;
    }



private:
    uint16_t *_buffer;
    uint32_t _count;
    uint32_t _index;

};


LaserdockSample * samples;
const uint32_t samples_per_packet = 64;
const uint32_t circle_steps = 300;


int main() {

    samples = (LaserdockSample *)calloc(sizeof(LaserdockSample), samples_per_packet);

    LaserdockDeviceManager &lddmanager = LaserdockDeviceManager::getInstance();
    LaserdockDevice * device =  lddmanager.get_next_available_device();

    print_uint32("Firmware major version", device, &LaserdockDevice::version_major_number);
    print_uint32("Firmware minor version", device, &LaserdockDevice::version_minor_number);
    print_uint32("Max Dac Rate", device, &LaserdockDevice::max_dac_rate);
    print_uint32("Min Dac Value", device, &LaserdockDevice::min_dac_value);
    print_uint32("Max Dac Value", device, &LaserdockDevice::max_dac_value);
    device->set_dac_rate(30000);
    print_uint32("Current Dac Rate", device, &LaserdockDevice::dac_rate);

    cout << "Clearing ringbuffer: " << device->clear_ringbuffer() << endl;

    bool enabled = false ;

    if(!device->enable_output()){
        cout << "Failed enabling output state" << endl;
    }

    if(!device->get_output(&enabled)){
        cout << "Failed reading output state" << endl;
    } else
    {
        cout << "Output Enabled/Disabled: " << enabled << endl;
    }


    CircleBuffer cbuffer(circle_steps);

    while(1){
        cbuffer.fillSamples(samples, samples_per_packet);
        device->send_samples(samples,samples_per_packet);
    }

    return 0;
}
