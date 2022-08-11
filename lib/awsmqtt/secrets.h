#include <pgmspace.h>

#define SECRET
#define THINGNAME "your ThingName"

const char AWS_IOT_ENDPOINT[] = "your end-point";

// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
%YOUR CERTIFICATE%
-----END CERTIFICATE-----
)EOF";

// Device Certificate
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
%YOUR CERTIFICATE%
-----END CERTIFICATE-----
)KEY";

// Device Private Key
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
%YOUR CERTIFICATE%
-----END RSA PRIVATE KEY-----
)KEY";