/**
 * Fast map matching.
 *
 * Result configuration class
 *
 * @author Can Yang
 */

#ifndef FMM_SRC_CONFIG_RESULT_CONFIG_HPP_
#define FMM_SRC_CONFIG_RESULT_CONFIG_HPP_

#include <string>
#include <set>
#include "cxxopts/cxxopts.hpp"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

namespace FMM {

namespace CONFIG {

/**
 *  Output configuration class defining the fields exported for map matching
 */
struct OutputConfig {
  bool write_opath = false; /**< if true, opath (edge id matched for
                                  each point) will be exported */
  bool write_offset = false; /**< if true, offset (distance to the start point
                                  of a matched edge) will be exported */
  bool write_error = false; /**< if true, gps error (distance from GPS point to
                                  the matched point) will be exported */
  bool write_cpath = true; /**< if true, cpath (a list of edge ID representing
                                the matched path) will be exported */
  bool write_tpath = false; /**< if true, tpath (the path traversed between
                                 each two consecutive observations)
                                 will be exported */
  bool write_mgeom = true; /**< if true, mgeom (the geometry of
                                the matched path) will be exported */
  bool write_spdist = false; /**< if true, spdist (the distance traversed
                                  between each two consecutive points)
                                  will be exported */
  bool write_pgeom = false; /**< if true, pgeom (a linestring connecting
                                 the matched point) will be exported */
  bool write_ep = false; /**< if true, ep (emission proability of each point)
                              will be exported */
  bool write_tp = false; /**< if true, tp (transition probability) will be
                              exported */
  bool write_length = false; /**< if true, length (length of each matched edge)
                                  will be exported */
  bool write_duration = false; /**< if true, duration (time difference between
                                  two points) will be exported */
  bool write_speed = false; /**< if true, speed (sp_dist/duration)
                                  will be exported */
};

/**
 * Result Configuration class, defining output file and output fields
 */
struct ResultConfig {
  std::string file; /**< Output file to write the result */
  OutputConfig output_config; /**< Output fields to export */
  /**
   * Check the validation of the configuration
   * @return true if valid otherwise false
   */
  bool validate() const;
  /**
   * Print the configuration information
   */
  void print() const;
  /**
   * Parse a string separated by , into a set of strings.
   *
   * This is used for extracting the output fields from argument
   *
   * @param s input string
   * @return a set of strings
   */
  static std::set<std::string> string2set(const std::string &s);
  /**
   * Load result configuration data from xml file
   * @param xml_data xml data parsed by reading an xml file
   * @return
   */
  static ResultConfig load_from_xml(
    const boost::property_tree::ptree &xml_data);
  /**
   * Load result configuration from argument data
   * @param arg_data argument data generated by reading arguments
   * @return
   */
  static ResultConfig load_from_arg(
    const cxxopts::ParseResult &arg_data);
  /**
   * Register arguments to an option object
   */
  static void register_arg(cxxopts::Options &options);
  /**
   * Register help information to a string stream
   */
  static void register_help(std::ostringstream &oss);
};
}

}

#endif //FMM_SRC_CONFIG_RESULT_CONFIG_HPP_
