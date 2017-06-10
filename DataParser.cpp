
// this one is trivial but have been implemented for consistency with other similar routines (for 16, 32 etc. bits)
uint8_t readU8(const uint8_t* data, uint8_t& value)
{
    value = data[0];
    return 1;
}

uint8_t readI8(const uint8_t* data, int8_t& value)
{
    value = data[0];
    return 1;
}

uint8_t readU16(const uint8_t* data, uint16_t& value)
{
    value = (data[0] << 8) | data[1];
    return 2;
}

uint8_t readI16(const uint8_t* data, int16_t&  value)
{
    value = (data[0] << 8) | data[1];
    return 2;
}

uint8_t readU32(const uint8_t* data, uint32_t& value)
{
    value = (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3];
    return 4;
}

uint8_t readI32(const uint8_t* data, int32_t&  value)
{
    value = (data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3];
    return 4;
}


uint8_t readF32(const uint8_t* data, float& value)
{
    union
    {
        float f;
        uint32_t i;
    } val;
    readU32(data, val.i);

    value = val.f;
    return 4;
}

uint8_t writeU8(uint8_t* data, uint8_t value)
{
    data[0] = value ;
    return 1;
}

uint8_t writeI8(uint8_t* data, int8_t value)
{
    data[0] = value;
    return 1;
}


uint8_t writeU16(uint8_t* data, uint16_t value)
{
    data[0] = (uint8_t)(value >> 8);
    data[1] = (uint8_t)(value & 0xFF);
    return 2;
}

uint8_t writeI16(uint8_t* data, int16_t  value)
{
    data[0] = (uint8_t)(value >> 8);
    data[1] = (uint8_t)(value & 0xFF);
    return 2;
}

uint8_t writeU32(uint8_t* data, uint32_t value)
{
    data[0] = (uint8_t)(value >> 24);
    data[1] = (uint8_t)(value >> 16);
    data[2] = (uint8_t)(value >> 8);
    data[3] = (uint8_t)(value & 0xFF);
    return 4;
}

uint8_t writeI32(uint8_t* data, int32_t  value)
{
    data[0] = (uint8_t)(value >> 24);
    data[1] = (uint8_t)(value >> 16);
    data[2] = (uint8_t)(value >> 8);
    data[3] = (uint8_t)(value & 0xFF);
    return 4;
}

uint8_t writeF32(uint8_t* data, float value)
{
    union
    {
        float f;
        uint32_t i;
    } val;

    val.f = value;

    writeU32(data, val.i);
    return 4;
}

uint8_t readBinary(const uint8_t *data, uint8_t *value, uint8_t size)
{
    uint8_t length = *(data++);

    uint8_t i = size > length ? length : size;

    while (i--)
        *(value++) = *(data++);

    return length + 1;
}

uint8_t writeBinary(uint8_t *data, uint8_t *value, uint8_t size)
{
    uint8_t i = size;

    *(data++) = size;

    while (i--)
        *(data++) = *(value++);

    return size + 1;
}
