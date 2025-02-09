// Copyright The OpenTelemetry Authors
// SPDX-License-Identifier: Apache-2.0

#pragma once

#include "opentelemetry/exporters/otlp/otlp_environment.h"
#include "opentelemetry/exporters/otlp/otlp_http.h"
#include "opentelemetry/exporters/otlp/otlp_preferred_temporality.h"
#include "opentelemetry/version.h"

#include <chrono>
#include <cstddef>
#include <memory>
#include <string>

OPENTELEMETRY_BEGIN_NAMESPACE
namespace exporter
{
namespace otlp
{

/**
 * Struct to hold OTLP HTTP metrics exporter options.
 *
 * See
 * https://github.com/open-telemetry/opentelemetry-proto/blob/main/docs/specification.md#otlphttp
 *
 * See
 * https://github.com/open-telemetry/opentelemetry-specification/blob/main/specification/protocol/exporter.md
 */
struct OPENTELEMETRY_EXPORT OtlpHttpMetricExporterOptions
{
  OtlpHttpMetricExporterOptions();
  ~OtlpHttpMetricExporterOptions();

  /** The endpoint to export to. */
  std::string url;

  /** HTTP content type. */
  HttpRequestContentType content_type;

  /**
    Json byte mapping.

    Used only for HttpRequestContentType::kJson.
    Convert bytes to hex / base64.
  */
  JsonBytesMappingKind json_bytes_mapping;

  /**
    Use json names (true) or protobuf field names (false) to set the json key.
  */
  bool use_json_name;

  /** Print debug messages. */
  bool console_debug;

  /** Export timeout. */
  std::chrono::system_clock::duration timeout;

  /** Additional HTTP headers. */
  OtlpHeaders http_headers;

  PreferredAggregationTemporality aggregation_temporality;

#ifdef ENABLE_ASYNC_EXPORT
  /** Max number of concurrent requests. */
  std::size_t max_concurrent_requests;

  /** Max number of requests per connection. */
  std::size_t max_requests_per_connection;
#endif

#ifdef ENABLE_OTLP_HTTP_SSL_PREVIEW
  /** True do disable SSL. */
  bool ssl_insecure_skip_verify;

  /** CA CERT, path to a file. */
  std::string ssl_ca_cert_path;

  /** CA CERT, as a string. */
  std::string ssl_ca_cert_string;

  /** CLIENT KEY, path to a file. */
  std::string ssl_client_key_path;

  /** CLIENT KEY, as a string. */
  std::string ssl_client_key_string;

  /** CLIENT CERT, path to a file. */
  std::string ssl_client_cert_path;

  /** CLIENT CERT, as a string. */
  std::string ssl_client_cert_string;
#endif /* ENABLE_OTLP_HTTP_SSL_PREVIEW */

#ifdef ENABLE_OTLP_HTTP_SSL_TLS_PREVIEW
  /** Minimum TLS version. */
  std::string ssl_min_tls;

  /** Maximum TLS version. */
  std::string ssl_max_tls;

  /** TLS cipher. */
  std::string ssl_cipher;

  /** TLS cipher suite. */
  std::string ssl_cipher_suite;
#endif /* ENABLE_OTLP_HTTP_SSL_TLS_PREVIEW */
};

}  // namespace otlp
}  // namespace exporter
OPENTELEMETRY_END_NAMESPACE
