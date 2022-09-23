#pragma once
#include <cmath>

double yearsToSeconds(double years)
{
  return years * 365.25 * 24 * 60 * 60;
}

// Mutiply a number by ten to the power. By default power is -9
double multiplyByTenToThePower(double number, double power = -9)
{
  return number * pow(10, power);
}

double orbitalSpeed(double period, double orbitRadius)
{
  return (orbitRadius * 2 * 3.14) / period;
}

struct BodyData
{
  double mass;
  double radius;
  double siderealPeriod;
  double orbitalRadius;

  BodyData(double radius, double mass, double siderealPeriod, double orbitalRadius)
  {
    this->radius = radius;
    this->mass = mass;
    this->siderealPeriod = siderealPeriod;
    this->orbitalRadius = orbitalRadius;
  };
};
const BodyData sunData(695508000, 1989100000.0 * pow(10, 21), 0, 0);

const double SUN = 234;
const BodyData mercuryData(
    2439400,
    330.11 * pow(10, 21),
    yearsToSeconds(0.240846),
    57900000000);
const BodyData venusData(
    6052000,
    4867.5 * pow(10, 21),
    yearsToSeconds(0.615),
    108200000000);

const BodyData earthData(
    6371000,
    5972.4 * pow(10, 21),
    yearsToSeconds(1),
    149600000000);

const BodyData marsData(
    3389500,
    641.71 * pow(10, 21),
    yearsToSeconds(1.881),
    227900000000);

const BodyData jupiterData(
    69911000,
    1898187 * pow(10, 21),
    yearsToSeconds(11.86),
    778600000000);

const BodyData saturnData(
    58232000,
    568317 * pow(10, 21),
    yearsToSeconds(29.46),
    1433500000000);

const BodyData uranusData(
    25362000,
    86813 * pow(10, 21),
    yearsToSeconds(84.01),
    2872500000000);

const BodyData neptunData(
    24622000,
    102413 * pow(10, 21),
    yearsToSeconds(164.8),
    4495100000000);
